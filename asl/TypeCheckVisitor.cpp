//////////////////////////////////////////////////////////////////////
//
//    TypeCheckVisitor - Walk the parser tree to do the semantic
//                       typecheck for the Asl programming language
//
//    Copyright (C) 2020-2030  Universitat Politecnica de Catalunya
//
//    This library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU General Public License
//    as published by the Free Software Foundation; either version 3
//    of the License, or (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public
//    License along with this library; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//
//    contact: José Miguel Rivero (rivero@cs.upc.edu)
//             Computer Science Department
//             Universitat Politecnica de Catalunya
//             despatx Omega.110 - Campus Nord UPC
//             08034 Barcelona.  SPAIN
//
//////////////////////////////////////////////////////////////////////

#include "TypeCheckVisitor.h"
#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/SemErrors.h"

#include <iostream>
#include <string>

// uncomment the following line to enable debugging messages with DEBUG*
#define DEBUG_BUILD
#include "../common/debug.h"

// using namespace std;


// Constructor
TypeCheckVisitor::TypeCheckVisitor(TypesMgr       & Types,
                                   SymTable       & Symbols,
                                   TreeDecoration & Decorations,
                                   SemErrors      & Errors) :
  Types{Types},
  Symbols{Symbols},
  Decorations{Decorations},
  Errors{Errors} {
}

// Accessor/Mutator to the attribute currFunctionType
TypesMgr::TypeId TypeCheckVisitor::getCurrentFunctionTy() const {
  return currFunctionType;
}

void TypeCheckVisitor::setCurrentFunctionTy(TypesMgr::TypeId type) {
  currFunctionType = type;
}

// Methods to visit each kind of node:
std::any TypeCheckVisitor::visitProgram(AslParser::ProgramContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  for (auto ctxFunc : ctx->function()) { 
    visit(ctxFunc);
  }
  if (Symbols.noMainProperlyDeclared())
    Errors.noMainProperlyDeclared(ctx);
  Symbols.popScope();
  Errors.print();
  DEBUG_EXIT();
  return 0;
}

//////////////////////////////////// FUNCTION ////////////////////////////////////

std::any TypeCheckVisitor::visitFunction(AslParser::FunctionContext *ctx) {
  DEBUG_ENTER();
  // Obtenemos el ID del scope actual, la funcion
  SymTable::ScopeId sc = getScopeDecor(ctx);
  // "Entramos en el scope", anadiendolo a la pila
  Symbols.pushThisScope(sc);
  // Symbols.print();

  TypesMgr::TypeId tRet;
  // Si la funcion tiene un tipo T, entonces el tipo de la funcion sera T
  if (ctx->type()) {
    visit(ctx->type());
    tRet = getTypeDecor(ctx->type());
  }
  // En caso contrario sera de tipo Void
  else tRet = Types.createVoidTy();

  std::cout << "FuncCurrentTypeD: " << Types.to_string(tRet) << std::endl;
  setCurrentFunctionTy(tRet);
  std::cout << "FuncCurrentTypeG: " << Types.to_string(getCurrentFunctionTy()) << std::endl;
  
  visit(ctx->statements());
  Symbols.popScope();
  DEBUG_EXIT();
  return 0;
  /// set type al entrar a la funcio y get type al return
}

// std::any TypeCheckVisitor::visitDeclarations(AslParser::DeclarationsContext *ctx) {
//   DEBUG_ENTER();
//   std::any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

// std::any TypeCheckVisitor::visitVariable_decl(AslParser::Variable_declContext *ctx) {
//   DEBUG_ENTER();
//   std::any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

// std::any TypeCheckVisitor::visitType(AslParser::TypeContext *ctx) {
//   DEBUG_ENTER();
//   std::any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

///////////////////////////////////////////////////////////////////////////////////////////
//                                   STATEMENTS                                          //
///////////////////////////////////////////////////////////////////////////////////////////

std::any TypeCheckVisitor::visitStatements(AslParser::StatementsContext *ctx) {
  DEBUG_ENTER();
  visitChildren(ctx);
  DEBUG_EXIT();
  return 0;
}

// ASSIGN STATEMENT
std::any TypeCheckVisitor::visitAssignStmt(AslParser::AssignStmtContext *ctx) {
  DEBUG_ENTER();
  // Decoramos ambos nodos
  visit(ctx->left_expr());
  visit(ctx->expr());

  // Obtenemos el tipo de cada lado de la asignacion
  TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());

  // Si no son errores y no son copiables (coercion de tipo) -> ERROR
  if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and
      (not Types.copyableTypes(t1, t2)))
    Errors.incompatibleAssignment(ctx->ASSIGN());

  // Si no es un error y no es un Lvalue -> ERROR
  if ((not Types.isErrorTy(t1)) and (not getIsLValueDecor(ctx->left_expr())))
    Errors.nonReferenceableLeftExpr(ctx->left_expr());

  DEBUG_EXIT();
  return 0;
}

// IF STATEMENT
std::any TypeCheckVisitor::visitIfStmt(AslParser::IfStmtContext *ctx) {
  DEBUG_ENTER();
  // Decoramos la expresion de la condicion
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());

  // Si la condicion no es de tipo error y no es un bool -> ERROR
  if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1)))
    Errors.booleanRequired(ctx);

  // Visitamos los statements tanto del if como del else
  visit(ctx->statements(0));
  if (ctx->ELSE()) visit(ctx->statements(1));
  DEBUG_EXIT();
  return 0;
}

// WHILE STATEMENT
std::any TypeCheckVisitor::visitWhileStmt(AslParser::WhileStmtContext *ctx) {
  DEBUG_ENTER();

  // Decoramos la expresion de la condicion
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());

  // Si la condicion no es de tipo error y no es un bool -> ERROR
  if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1)))
    Errors.booleanRequired(ctx);

  // Visitamos y decoramos los statements
  visit(ctx->statements());
  DEBUG_EXIT();
  return 0;
}

// PROC STATEMENT
std::any TypeCheckVisitor::visitProcCall(AslParser::ProcCallContext *ctx) {
  DEBUG_ENTER();
  // Decoramos el tipo del ID de la funcion
  visit(ctx->ident());
  TypesMgr::TypeId funcID = getTypeDecor(ctx->ident());

  TypesMgr::TypeId t;
  // Si no es una funcion
  if (not Types.isFunctionTy(funcID)) {
    if (not(Types.isErrorTy(funcID))) Errors.isNotCallable(ctx->ident());
    t = Types.createErrorTy();

    // Visitamos y decoramos los parametros siempre
    for (auto param : ctx->expr()) visit(param);
  }
  else{
    // Si es una funcion pero no es un procedimiento -> ERROR
    if (not(Types.isVoidFunction(funcID))) t = Types.createErrorTy();
    else t = Types.getFuncReturnType(funcID);

    uint i = 0; // Indice de los pametros en la declaracion de la funcion
    for (auto param : ctx->expr()) {
      // Decoramos el parametro de la llamada
      visit(param);
      TypesMgr::TypeId tParam = getTypeDecor(param);
      
      // funcParam es el tipo del parametro cuando se declaro la funcion
      TypesMgr::TypeId funcParam;
      if (i < Types.getNumOfParameters(funcID)) funcParam = Types.getParameterType(funcID,i);
      // Si hay mas parametros en la llamada que en la declaracion de la función -> ERROR
      else funcParam = Types.createErrorTy();


      std::cout << "Expected Param Type: " <<  Types.to_string(funcParam) << std::endl ;
      std::cout << "Param Type: " << param->getText() << " " <<  Types.to_string(tParam) << std::endl ;
      std::cout << "Param Type Check: " << ((not Types.isErrorTy(tParam))) << " " <<  (not Types.copyableTypes(funcParam, tParam)) << std::endl ;


      // Si los parametros no son Error y no son copiables -> ERROR
      if ((not Types.isErrorTy(tParam)) and
          (not Types.isErrorTy(funcParam)) and
          (not Types.copyableTypes(funcParam, tParam))) {
            Errors.incompatibleParameter(param, i+1, ctx);
            t = Types.createErrorTy();
          }

      // Pasamos al siguiente parametro
      ++i;
    }

    // Si el numero de paramtros de la llamada y el la funcion declara son diferentes
    if(ctx->expr().size() != Types.getNumOfParameters(funcID))
      Errors.numberOfParameters(ctx->ident());
  }

  std::cout << "Function Type: " <<  Types.to_string(t) << std::endl ;
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

// READ STATEMENT
std::any TypeCheckVisitor::visitReadStmt(AslParser::ReadStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->left_expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isPrimitiveTy(t1)) and
      (not Types.isFunctionTy(t1)))
    Errors.readWriteRequireBasic(ctx);
  if ((not Types.isErrorTy(t1)) and (not getIsLValueDecor(ctx->left_expr())))
    Errors.nonReferenceableExpression(ctx);
  DEBUG_EXIT();
  return 0;
}

// WRITE STATEMENT
std::any TypeCheckVisitor::visitWriteExpr(AslParser::WriteExprContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isPrimitiveTy(t1)))
    Errors.readWriteRequireBasic(ctx);
  DEBUG_EXIT();
  return 0;
}

// RETURN STATEMENT
std::any TypeCheckVisitor::visitReturnStmt(AslParser::ReturnStmtContext *ctx) {
  DEBUG_ENTER();
  // Obtenemos el tipo de la funcion
  TypesMgr::TypeId tRet = getCurrentFunctionTy();
  std::cout << "FuncType: " << Types.to_string(tRet) << std::endl;

  // Si es una funcion retornamos la evaluacion de la expresion
  if(ctx->expr()){
    // Obtenemos el tipo del Return
    visit(ctx->expr());
    TypesMgr::TypeId tExpr = getTypeDecor(ctx->expr());
    std::cout << "Return Expresion Type: " << Types.to_string(tExpr) << std::endl;    

    // Si ninguno de los dos es un error y no son copiables -> ERROR
    if(not(Types.isErrorTy(tRet)) and not(Types.isErrorTy(tExpr)) and not(Types.copyableTypes(tRet, tExpr))) {
      Errors.incompatibleReturn(ctx->RETURN());
      tRet = Types.createErrorTy();
    }
  }
  // Si es un procedimiento retonamos void
  else {
    // Si el tipo de la funcion no es un error y no es void -> ERROR
    if(not(Types.isErrorTy(tRet)) and not(Types.isVoidTy(tRet))){   
      Errors.incompatibleReturn(ctx->RETURN());
      tRet = Types.createErrorTy();
    }
  }

  putTypeDecor(ctx, tRet);
  std::cout << "Return Final Type: " << Types.to_string(tRet) << std::endl; 
  DEBUG_EXIT();
  return 0;
}

// std::any TypeCheckVisitor::visitWriteString(AslParser::WriteStringContext *ctx) {
//   DEBUG_ENTER();
//   std::any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

std::any TypeCheckVisitor::visitLeft_expr(AslParser::Left_exprContext *ctx) {
  DEBUG_ENTER();

  // IDENTIFICADOR
  if (not(ctx->expr())) {
    // Obtenemos el tipo del ID
    visit(ctx->ident());
    TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
    putTypeDecor(ctx, t1);

    // Vemos si es LValue
    bool b = getIsLValueDecor(ctx->ident());
    putIsLValueDecor(ctx, b);
  }
  // ACCESO A UN ARRAY
  else{
    // Decoramos y obtenemos el tipo de el ID del array y de la Expr
    visit(ctx->expr());
    visit(ctx->ident());
    TypesMgr::TypeId tArray = getTypeDecor(ctx->ident()); // El ID sera de tipo ARRAY
    TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());      // La expr tendra que ser de tipo INT
    TypesMgr::TypeId tElementTy = Types.createErrorTy();  // El tipo de los elementos del array

    // Si no es un error y no es un array -> ERROR
    if (((not Types.isErrorTy(tArray)) and (not Types.isArrayTy(tArray))))
      Errors.nonArrayInArrayAccess(ctx);

    // Si el ID es de tipo Array obtenemos el tipo de sus elementos
    if (Types.isArrayTy(tArray) and not(Types.isErrorTy(tArray))) tElementTy = Types.getArrayElemType(tArray);

    // Si no es un error o no es un INT -> ERROR
    if (((not Types.isErrorTy(t1)) and (not Types.isIntegerTy(t1))))
      Errors.nonIntegerIndexInArrayAccess(ctx->expr());
    
    bool b = getIsLValueDecor(ctx->ident());
    putIsLValueDecor(ctx, b);
    putTypeDecor(ctx, tElementTy);
  }

  DEBUG_EXIT();
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//                                   EXPRESIONS                                          //
///////////////////////////////////////////////////////////////////////////////////////////

std::any TypeCheckVisitor::visitUnary(AslParser::UnaryContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId tExpr = getTypeDecor(ctx->expr());
  TypesMgr::TypeId tFinal = tExpr;

  // Operador unario BOOLEANO
  if (ctx->NOT()) {
    if (not(Types.isErrorTy(tExpr)) and not(Types.isBooleanTy(tExpr))) {
      Errors.incompatibleOperator(ctx->op);
      tFinal = Types.createErrorTy();
    }
  }
  // Operador unario ARITMETICO
  else {
    if (not(Types.isErrorTy(tExpr)) and not(Types.isNumericTy(tExpr))) {
      if (ctx->PLUS()) Errors.incompatibleOperator(ctx->op);
      else Errors.incompatibleOperator(ctx->op);
      tFinal = Types.createErrorTy();
    }
  }

  putTypeDecor(ctx, tFinal);
  DEBUG_EXIT();
  return 0;
}

std::any TypeCheckVisitor::visitArithmetic(AslParser::ArithmeticContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));

  TypesMgr::TypeId t = Types.createIntegerTy();
  if (ctx->MODULO()) {
    if (((not Types.isErrorTy(t1)) and (not Types.isIntegerTy(t1))) or
      ((not Types.isErrorTy(t2)) and (not Types.isIntegerTy(t2))))
    Errors.incompatibleOperator(ctx->op);
  }
  else{
    if (((not Types.isErrorTy(t1)) and (not Types.isNumericTy(t1))) or
        ((not Types.isErrorTy(t2)) and (not Types.isNumericTy(t2))))
      Errors.incompatibleOperator(ctx->op);
    if (Types.isFloatTy(t1) or Types.isFloatTy(t2)) t = Types.createFloatTy();
  }  

  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

std::any TypeCheckVisitor::visitLogical(AslParser::LogicalContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));

  if (((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1))) or
      ((not Types.isErrorTy(t2)) and (not Types.isBooleanTy(t2))))
    Errors.incompatibleOperator(ctx->op);

  TypesMgr::TypeId t = Types.createBooleanTy();

  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

std::any TypeCheckVisitor::visitRelational(AslParser::RelationalContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  std::string oper = ctx->op->getText();

  if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and
      (not Types.comparableTypes(t1, t2, oper)))
    Errors.incompatibleOperator(ctx->op);

  TypesMgr::TypeId t = Types.createBooleanTy();

  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}
 
std::any TypeCheckVisitor::visitValue(AslParser::ValueContext *ctx) {
  DEBUG_ENTER();
  TypesMgr::TypeId t;
  
  if (ctx->INTVAL()) t = Types.createIntegerTy();
  else if (ctx->FLOATVAL()) t = Types.createFloatTy();
  else if (ctx->CHARVAL()) t = Types.createCharacterTy();
  else t = Types.createBooleanTy();

  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

std::any TypeCheckVisitor::visitExprIdent(AslParser::ExprIdentContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());

  bool b = getIsLValueDecor(ctx->ident());
  putIsLValueDecor(ctx, b);
  putTypeDecor(ctx, t1);
  DEBUG_EXIT();
  return 0;
}

std::any TypeCheckVisitor::visitIdent(AslParser::IdentContext *ctx) {
  DEBUG_ENTER();
  std::string ident = ctx->getText();
  if (Symbols.findInStack(ident) == -1) {
    Errors.undeclaredIdent(ctx->ID());
    TypesMgr::TypeId te = Types.createErrorTy();
    putTypeDecor(ctx, te);
    putIsLValueDecor(ctx, true);
  }
  else {
    TypesMgr::TypeId t1 = Symbols.getType(ident);
    putTypeDecor(ctx, t1);
    if (Symbols.isFunctionClass(ident))
      putIsLValueDecor(ctx, false);
    else
      putIsLValueDecor(ctx, true);
  }
  DEBUG_EXIT();
  return 0;
}

std::any TypeCheckVisitor::visitExprArray(AslParser::ExprArrayContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());
  TypesMgr::TypeId tArray = getTypeDecor(ctx->ident());
  TypesMgr::TypeId tFinal;

  // El tipo de X en ID[X]
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());

  //check ArrayType
  if (((not Types.isErrorTy(tArray)) and (not Types.isArrayTy(tArray))) ) {
    Errors.nonArrayInArrayAccess(ctx);
    tFinal = Types.createErrorTy();
  }
  else {
    if(not(Types.isErrorTy(tArray))) tFinal = Types.getArrayElemType(tArray);
    else tFinal = Types.createErrorTy();
  }


  // Mirar si el indice es un INT
  if (((not Types.isErrorTy(t1)) and (not Types.isIntegerTy(t1))))
    Errors.nonIntegerIndexInArrayAccess(ctx->expr());

  putTypeDecor(ctx, tFinal);
  DEBUG_EXIT();
  return 0;
}

std::any TypeCheckVisitor::visitFuncCall(AslParser::FuncCallContext *ctx) {
  DEBUG_ENTER();
  // Decoramos el tipo del ID de la funcion
  visit(ctx->ident());
  TypesMgr::TypeId funcID = getTypeDecor(ctx->ident());
  TypesMgr::TypeId t;

  // Si no es una funcion
  if (not Types.isFunctionTy(funcID)) {
    if(not(Types.isErrorTy(funcID))) Errors.isNotCallable(ctx);
    t = Types.createErrorTy();

    // Visitamos y decoramos los parametros siempre
    for (auto param : ctx->expr()) visit(param);
  }
  else{
    // Si es una funcion pero es un procedimiento
    if (Types.isVoidFunction(funcID)) {
      Errors.isNotFunction(ctx);
      t = Types.createErrorTy();
    }
    else t = Types.getFuncReturnType(funcID);

    uint i = 0; // Indice de los pametros en la declaracion de la funcion
    for (auto param : ctx->expr()) {
      // Decoramos el parametro de la llamada
      visit(param);
      TypesMgr::TypeId tParam = getTypeDecor(param);

      // funcParam es el tipo del parametro cuando se declaro la funcion
      TypesMgr::TypeId funcParam;
      if(i < Types.getNumOfParameters(funcID)) funcParam = Types.getParameterType(funcID,i);
      // Si hay mas parametros en la llamada que en la declaracion de la función -> ERROR
      else funcParam = Types.createErrorTy();


      std::cout << std::endl << "Function: " <<  ctx->getText() << std::endl ;
      std::cout << "Expected Param Type: " <<  Types.to_string(funcParam) << std::endl ;
      std::cout << "Param Type: " << param->getText() << " " <<  Types.to_string(tParam) << std::endl ;
      std::cout << "Param Type Check: " << ((not Types.isErrorTy(tParam))) << " " <<  (not Types.copyableTypes(funcParam, tParam)) << std::endl ;
        

      // Si los parametros no son Error y no son copiables -> ERROR
      if ((not Types.isErrorTy(tParam)) and
          (not Types.copyableTypes(funcParam, tParam)) and
          (not Types.isErrorTy(funcParam))) {
            Errors.incompatibleParameter(param, i+1, ctx);
      }

      // Pasamos al siguiente parametro
      ++i;
    }

    // Si el numero de paramtros de la llamada y el la funcion declara son diferentes
    if(ctx->expr().size() != Types.getNumOfParameters(funcID))
      Errors.numberOfParameters(ctx->ident());
  }

  std::cout << "Function Type: " <<  Types.to_string(t) << std::endl ;
  putTypeDecor(ctx, t); 
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

std::any TypeCheckVisitor::visitParent(AslParser::ParentContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t = getTypeDecor(ctx->expr());

  putTypeDecor(ctx, t);
  DEBUG_EXIT();
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Getters for the necessary tree node atributes:
//   Scope, Type ans IsLValue
SymTable::ScopeId TypeCheckVisitor::getScopeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getScope(ctx);
}

TypesMgr::TypeId TypeCheckVisitor::getTypeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getType(ctx);
}

bool TypeCheckVisitor::getIsLValueDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getIsLValue(ctx);
}

// Setters for the necessary tree node attributes:
//   Scope, Type ans IsLValue
void TypeCheckVisitor::putScopeDecor(antlr4::ParserRuleContext *ctx, SymTable::ScopeId s) {
  Decorations.putScope(ctx, s);
}

void TypeCheckVisitor::putTypeDecor(antlr4::ParserRuleContext *ctx, TypesMgr::TypeId t) {
  Decorations.putType(ctx, t);
}

void TypeCheckVisitor::putIsLValueDecor(antlr4::ParserRuleContext *ctx, bool b) {
  Decorations.putIsLValue(ctx, b);
}
