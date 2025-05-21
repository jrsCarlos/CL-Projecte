//////////////////////////////////////////////////////////////////////
//
//    CodeGenVisitor - Walk the parser tree to do
//                     the generation of code
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

#include "CodeGenVisitor.h"
#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/code.h"

#include <string>
#include <cstddef>    // std::size_t

// uncomment the following line to enable debugging messages with DEBUG*
//#define DEBUG_BUILD
#include "../common/debug.h"

// using namespace std;


// Constructor
CodeGenVisitor::CodeGenVisitor(TypesMgr       & Types,
                               SymTable       & Symbols,
                               TreeDecoration & Decorations) :
  Types{Types},
  Symbols{Symbols},
  Decorations{Decorations} {
}

// Accessor/Mutator to the attribute currFunctionType
TypesMgr::TypeId CodeGenVisitor::getCurrentFunctionTy() const {
  return currFunctionType;
}

void CodeGenVisitor::setCurrentFunctionTy(TypesMgr::TypeId type) {
  currFunctionType = type;
}

// Methods to visit each kind of node:
//
std::any CodeGenVisitor::visitProgram(AslParser::ProgramContext *ctx) {
  DEBUG_ENTER();
  code my_code;
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  for (auto ctxFunc : ctx->function()) {
    subroutine subr = std::any_cast<subroutine>(visit(ctxFunc));
    my_code.add_subroutine(subr);
  }
  Symbols.popScope();
  DEBUG_EXIT();
  return my_code;
}

std::any CodeGenVisitor::visitFunction(AslParser::FunctionContext *ctx) {
  DEBUG_ENTER();
  // Crea el nuevo entorno para la funcion
  SymTable::ScopeId sc = getScopeDecor(ctx);
  // Añadimos el nuevo entorno a la tabla de simbolos
  // de ahora en adelante todo se procesara dentro de este nuevo entorno
  Symbols.pushThisScope(sc);

  // Pillamos el nombre de la funcion y cremos la subrutina
  subroutine subr(ctx->ID()->getText());

  // Limpiamos todo antes de comenzar
  codeCounters.reset();

  // El primer parametro que anadimos simepre es el return
  if (ctx->type()) {
    TypesMgr::TypeId returnTy = getTypeDecor(ctx->type());
    subr.add_param("_return_value",Types.to_string(returnTy),false);
  }
  // Afegim els parametres
  if (ctx->parameters()) {
    for (auto param : ctx->parameters()->parameter()) {
      std::string name = param->ID()->getText();
      TypesMgr::TypeId type = getTypeDecor(param);

      if (Types.isArrayTy(type)) {
        TypesMgr::TypeId arrayElemTy = Types.getArrayElemType(type);
        subr.add_param(name,Types.to_string(arrayElemTy),true);
      }
      else subr.add_param(name,Types.to_string(type),false);
    }
  }

  std::vector<var> && lvars = std::any_cast<std::vector<var>>(visit(ctx->declarations()));
  for (auto & onevar : lvars) subr.add_var(onevar);

  instructionList && code = std::any_cast<instructionList>(visit(ctx->statements()));

  code = code || instruction(instruction::RETURN());

  subr.set_instructions(code);
  Symbols.popScope();
  DEBUG_EXIT();
  return subr;
}

std::any CodeGenVisitor::visitDeclarations(AslParser::DeclarationsContext *ctx) {
  DEBUG_ENTER();
  std::vector<var> lvars;
  for (auto & varDeclCtx : ctx->variable_decl()) {
    std::vector<var> vars = std::any_cast<std::vector<var>> (visit(varDeclCtx));
    for (auto & onevar : vars) lvars.push_back(onevar);
  }
  DEBUG_EXIT();
  return lvars;
}

std::any CodeGenVisitor::visitVariable_decl(AslParser::Variable_declContext *ctx) {
  DEBUG_ENTER();
  TypesMgr::TypeId   t1 = getTypeDecor(ctx->type());
  std::size_t      size = Types.getSizeOfType(t1);
  std::vector<var> vars;

  for (auto ID : ctx->ID()) {
    // id->getText(): el nom de la variable id
    // Types.to_string(t1): el tipus de la variables
    // size: la mida del tipus de la variable
    if (Types.isArrayTy(t1)) t1 = Types.getArrayElemType(t1);
    vars.push_back(var{ID->getText(), Types.to_string(t1), size});
  }

  DEBUG_EXIT();
  return vars;
}

std::any CodeGenVisitor::visitStatements(AslParser::StatementsContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  for (auto stCtx : ctx->statement()) {
    instructionList && codeS =  std::any_cast<instructionList>(visit(stCtx));
    code = code || codeS;
  }
  DEBUG_EXIT();
  return code;
}

std::any CodeGenVisitor::visitAssignStmt(AslParser::AssignStmtContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  CodeAttribs     && codAtsE1 =  std::any_cast<CodeAttribs>(visit(ctx->left_expr()));
  std::string           addr1 = codAtsE1.addr;
  std::string           offs1 = codAtsE1.offs;
  instructionList &     code1 = codAtsE1.code;
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());
  
  CodeAttribs     && codAtsE2 = std::any_cast<CodeAttribs>(visit(ctx->expr()));
  std::string           addr2 = codAtsE2.addr;
  std::string           offs2 = codAtsE2.offs;
  instructionList &     code2 = codAtsE2.code;
  TypesMgr::TypeId tid2 = getTypeDecor(ctx->expr());
  std:: string temp = '%' +codeCounters.newTEMP();
  code = code1 || code2;

  // Asignacion de dos arrays
  if (Types.isArrayTy(tid1) and Types.isArrayTy(tid2)) {

  std::string label = codeCounters.newLabelWHILE();
  std::string labelBeginAssing = "beginAssign" + label;
  std::string labelEndAssign = "endAssign" + label;

  std::string counter = "%"+codeCounters.newTEMP();
  std::string condition = "%"+codeCounters.newTEMP();
  std::string sizeArray = "%"+codeCounters.newTEMP();
  std::string one = "%"+codeCounters.newTEMP();
  std::string tempAux = "%"+codeCounters.newTEMP();

  code = code || instruction::ILOAD(counter, "0");
  code = code || instruction::ILOAD(sizeArray, std::to_string (Types.getArraySize(tid1)));
  code = code || instruction::ILOAD(one, "1");
  code = code || instruction::LABEL(labelBeginAssing);
  code = code || instruction::LT(condition, counter, sizeArray);
  code = code || instruction::FJUMP(condition,labelEndAssign);
  code = code || instruction::LOADX(tempAux, addr2, counter);
  code = code || instruction::XLOAD(addr1, counter, tempAux);
  code = code || instruction::ADD(counter, counter, one);
  code = code || instruction::UJUMP(labelBeginAssing);
  code = code || instruction::LABEL(labelEndAssign);
    
  }

  else if (Types.isFloatTy(tid1) and Types.isIntegerTy(tid2)) {
    code = code || instruction::FLOAT(temp,addr2);
    addr2 = temp;
  }

  else if (ctx->left_expr()->expr()) {
    // A[expr] = n
    code = code || instruction::XLOAD(addr1, offs1, addr2);
  }
  else code = code || instruction::LOAD(addr1, addr2);

  DEBUG_EXIT();
  return code;
}

std::any CodeGenVisitor::visitIfStmt(AslParser::IfStmtContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  CodeAttribs     && codAtsE = std::any_cast<CodeAttribs>(visit(ctx->expr()));
  std::string          addr1 = codAtsE.addr;
  instructionList &    code1 = codAtsE.code;
  instructionList &&   code2 = std::any_cast<instructionList>(visit(ctx->statements(0)));
  std::string label = codeCounters.newLabelIF();
  std::string labelEndIf = "endif"+label;
  if(ctx->ELSE()){
    instructionList &&   codeStmtElse = std::any_cast<instructionList>(visit(ctx->statements(1)));
    std::string labelEndElse = "endelse"+label;
    code = code1 || instruction::FJUMP(addr1, labelEndIf) ||
         code2 || instruction::UJUMP(labelEndElse) || instruction::LABEL(labelEndIf) ||
         codeStmtElse || instruction::LABEL(labelEndElse);
  }
  else{
    code = code1 || instruction::FJUMP(addr1, labelEndIf) || code2 || instruction::LABEL(labelEndIf);
  }

  DEBUG_EXIT();
  return code;
}

// std::any CodeGenVisitor::visitProcCall(AslParser::ProcCallContext *ctx) {
//   DEBUG_ENTER();
//   instructionList code;
//   // std::string name = ctx->ident()->ID()->getSymbol()->getText();
//   std::string name = ctx->ident()->getText();
//   code = instruction::CALL(name);
//   DEBUG_EXIT();
//   return code;
// }

std::any CodeGenVisitor::visitReadStmt(AslParser::ReadStmtContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAtsE = std::any_cast<CodeAttribs>(visit(ctx->left_expr()));
  std::string          addr1 = codAtsE.addr;
  std::string          offs1 = codAtsE.offs;
  instructionList &    code1 = codAtsE.code;
  instructionList &     code = code1;
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());

  if(ctx->left_expr()->expr()) {
    std:: string temp = '%' +codeCounters.newTEMP();

    if (Types.isIntegerTy(tid1) or Types.isBooleanTy(tid1)) code = code || instruction::READI(temp);
    else if (Types.isFloatTy(tid1)) code = code || instruction::READF(temp);
    else code = code || instruction::READC(temp);

    code = code || instruction::XLOAD(addr1,offs1,temp);
  }
  else {
    if (Types.isIntegerTy(tid1) or Types.isBooleanTy(tid1)) code = code || instruction::READI(addr1);
    else if (Types.isFloatTy(tid1)) code = code || instruction::READF(addr1);
    else code = code || instruction::READC(addr1);
  }

  DEBUG_EXIT();
  return code;
}

std::any CodeGenVisitor::visitWriteExpr(AslParser::WriteExprContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = std::any_cast<CodeAttribs>(visit(ctx->expr()));
  std::string         addr1 = codAt1.addr;
  std::string         offs1 = codAt1.offs;
  instructionList &   code1 = codAt1.code;
  instructionList &    code = code1;
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->expr());
  // if (ctx->expr()->exprArray()) {
  //   std:: string temp = '%' +codeCounters.newTEMP();
  //   code = code || instruction::LOADX(temp,addr1,offs1);
  //   tid1 = Types.getArrayElemType(tid1);

  //   if (Types.isCharacterTy(tid1)) code = code || instruction::WRITEC(addr1);
  //   else if (Types.isFloatTy(tid1)) code = code || instruction::WRITEF(addr1);
  //   else code = code1 || instruction::WRITEI(addr1);
  // }
  // else {

    if (Types.isCharacterTy(tid1)) code = code || instruction::WRITEC(addr1);
    else if (Types.isFloatTy(tid1)) code = code || instruction::WRITEF(addr1);
    else code = code1 || instruction::WRITEI(addr1);
  //}
  DEBUG_EXIT();
  return code;
}

std::any CodeGenVisitor::visitWriteString(AslParser::WriteStringContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  std::string s = ctx->STRING()->getText();
  code = code || instruction::WRITES(s);
  DEBUG_EXIT();
  return code;
}

std::any CodeGenVisitor::visitLeft_expr(AslParser::Left_exprContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs && codAts = std::any_cast<CodeAttribs>(visit(ctx->ident()));
  std::string         addr = codAts.addr;
  instructionList &   code = codAts.code;

  std::string addrOff = "";
  std::string temp = addr;
  if (ctx->expr()) {
    CodeAttribs     && codAt1 = std::any_cast<CodeAttribs>(visit(ctx->expr()));
    addrOff = codAt1.addr;
    instructionList &   code1 = codAt1.code;
    code = code || code1;

    std::string arrName = ctx->ident()->getText();
    if (Symbols.isParameterClass(arrName)) {
      temp = "%"+codeCounters.newTEMP();
      code = code || instruction::LOAD(temp,addr);
    }
  }

  CodeAttribs codFinal(temp, addrOff, code);
  DEBUG_EXIT();
  return codFinal;
}

std::any CodeGenVisitor::visitExprArray(AslParser::ExprArrayContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs && codAts = std::any_cast<CodeAttribs>(visit(ctx->ident()));
  std::string         addr = codAts.addr;
  instructionList &   code = codAts.code;
  
  CodeAttribs     && codAt1 = std::any_cast<CodeAttribs>(visit(ctx->expr()));
  std::string         addrOff = codAt1.addr;
  instructionList &   codeOff = codAt1.code;

  std::string arrName = ctx->ident()->getText();
  std::string tempPointer = addr;
  if (Symbols.isParameterClass(arrName)) {
    tempPointer = "%"+codeCounters.newTEMP();
    code = code || instruction::LOAD(tempPointer,addr);
  }

  std::string temp = "%"+codeCounters.newTEMP();
  code = code || codeOff || instruction::LOADX(temp, tempPointer, addrOff);
  CodeAttribs codFinal(temp, "", code);
  DEBUG_EXIT();
  return codFinal;
}

std::any CodeGenVisitor::visitWhileStmt(AslParser::WhileStmtContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = std::any_cast<CodeAttribs>(visit(ctx->expr()));
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;

  instructionList && code2 = std::any_cast<instructionList>(visit(ctx->statements()));

  instructionList code;
  std::string label = codeCounters.newLabelWHILE();
  std::string labelBeginWhile = "beginWhile" + label;
  std::string labelEndWhile = "endWhile" + label;

  code = code || instruction::LABEL(labelBeginWhile);
  code = code || code1;
  code = code || instruction::FJUMP(addr1,labelEndWhile);
  code = code || code2;
  code = code || instruction::UJUMP(labelBeginWhile);
  code = code || instruction::LABEL(labelEndWhile);

  DEBUG_EXIT();
  return code;
}

std::any CodeGenVisitor::visitReturnStmt(AslParser::ReturnStmtContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  if (ctx->expr()) {
    CodeAttribs     && codeAtt = std::any_cast<CodeAttribs>(visit(ctx->expr()));
    std::string           addr = codeAtt.addr;
    instructionList &    code1 = codeAtt.code;
    code = code1 || instruction::LOAD("_return_value", addr);
  }
  code = code || instruction::RETURN();
  DEBUG_EXIT();
  return code;
}

std::any CodeGenVisitor::visitFuncCall(AslParser::FuncCallContext *ctx) {
  DEBUG_ENTER();
  instructionList codeFinal;
  instructionList codePush;
  instructionList codePop;
  codeFinal = codeFinal || instruction::PUSH();

  TypesMgr::TypeId funcID = getTypeDecor(ctx->ident());

  uint i = 0;
  for (auto expr : ctx->expr()) {
    TypesMgr::TypeId tParam = getTypeDecor(expr);
    TypesMgr::TypeId expectedParam = Types.getParameterType(funcID,i);

    CodeAttribs     && codAtPush = std::any_cast<CodeAttribs>(visit(expr));
    std::string         addrPush = codAtPush.addr;
    instructionList     code     = codAtPush.code;         
    codePush = codePush || code;

    if(Types.isFloatTy(expectedParam) and Types.isIntegerTy(tParam)) 
      codePush = codePush || instruction::FLOAT(addrPush, addrPush);

    if (Types.isArrayTy(tParam)) {
      std::string temp = "%"+codeCounters.newTEMP();
      codePush = codePush || instruction::ALOAD(temp,addrPush) || instruction::PUSH(temp);
    }
    else codePush = codePush || instruction::PUSH(addrPush);

    codePop  = codePop  || instruction::POP();
    ++i;
  }

  std::string funcName = ctx->ident()->getText();
  codeFinal = codeFinal ||codePush || instruction::CALL(funcName) || codePop;

  std::string temp = "%"+codeCounters.newTEMP();
  codeFinal = codeFinal || instruction::POP(temp);

  CodeAttribs codAts(temp, "", codeFinal);
  DEBUG_EXIT();
  return codAts;
}

std::any CodeGenVisitor::visitProcCall(AslParser::ProcCallContext *ctx) {
  DEBUG_ENTER();
  instructionList codeFinal;
  instructionList codePush;
  instructionList codePop;
  codeFinal = codeFinal || instruction::PUSH();

  TypesMgr::TypeId funcID = getTypeDecor(ctx->ident());

  uint i = 0;
  for (auto expr : ctx->expr()) {
    TypesMgr::TypeId tParam = getTypeDecor(expr);
    TypesMgr::TypeId expectedParam = Types.getParameterType(funcID,i);

    CodeAttribs     && codAtPush = std::any_cast<CodeAttribs>(visit(expr));
    std::string         addrPush = codAtPush.addr;
    instructionList     code     = codAtPush.code;         
    codePush = codePush || code;

    if(Types.isFloatTy(expectedParam) and Types.isIntegerTy(tParam)) 
      codePush = codePush || instruction::FLOAT(addrPush, addrPush);

    if (Types.isArrayTy(tParam)) {
      std::string temp = "%"+codeCounters.newTEMP();
      codePush = codePush || instruction::ALOAD(temp,addrPush) || instruction::PUSH(temp);
    }
    else codePush = codePush || instruction::PUSH(addrPush);

    codePop  = codePop  || instruction::POP();
    ++i;
  }

  std::string funcName = ctx->ident()->getText();
  codeFinal = codeFinal ||codePush || instruction::CALL(funcName) || codePop;

  std::string temp = "%"+codeCounters.newTEMP();
  codeFinal = codeFinal || instruction::POP(temp);

  DEBUG_EXIT();
  return codeFinal;
}

std::any CodeGenVisitor::visitParent(AslParser::ParentContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAt = std::any_cast<CodeAttribs>(visit(ctx->expr()));
  std::string         addr = codAt.addr;
  instructionList &   code = codAt.code;

  CodeAttribs codAts(addr, "", code);
  DEBUG_EXIT();
  return codAts;
}

std::any CodeGenVisitor::visitUnary(AslParser::UnaryContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAt = std::any_cast<CodeAttribs>(visit(ctx->expr()));
  std::string         addr = codAt.addr;
  instructionList &   code = codAt.code;

  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());

  std::string temp = "%"+codeCounters.newTEMP();

  if (ctx->NOT()) code = code || instruction::NOT(temp,addr);
  else if (ctx->MINUS()) {
    if (Types.isFloatTy(t1)) code = code || instruction::FNEG(temp,addr);
    else code = code || instruction::NEG(temp,addr);
  }
  else temp = addr;

  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

std::any CodeGenVisitor::visitArithmetic(AslParser::ArithmeticContext *ctx) {
  DEBUG_ENTER();
  
  CodeAttribs     && codAt1 = std::any_cast<CodeAttribs>(visit(ctx->expr(0)));
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;

  CodeAttribs     && codAt2 = std::any_cast<CodeAttribs>(visit(ctx->expr(1)));
  std::string         addr2 = codAt2.addr;
  instructionList &   code2 = codAt2.code;
  instructionList &&   code = code1 || code2;

  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));

  std::string temp = "%"+codeCounters.newTEMP();
  if (Types.isFloatTy(t1) or Types.isFloatTy(t2)) {
    std::string temp1 = "%"+codeCounters.newTEMP();
    std::string temp2 = "%"+codeCounters.newTEMP();

    if (Types.isIntegerTy(t1)) code = code || instruction::FLOAT(temp1,addr1);
    else temp1 = addr1;
    if (Types.isIntegerTy(t2)) code = code || instruction::FLOAT(temp2,addr2);
    else temp2 = addr2;

    if (ctx->MUL()) code = code || instruction::FMUL(temp, temp1, temp2);
    else if (ctx->DIV()) code = code || instruction::FDIV(temp, temp1, temp2);
    else if (ctx->PLUS()) code = code || instruction::FADD(temp, temp1, temp2);
    else code = code || instruction::FSUB(temp, temp1, temp2);
  }
  else {
    if (ctx->MUL()) code = code || instruction::MUL(temp, addr1, addr2);
    else if (ctx->DIV()) code = code || instruction::DIV(temp, addr1, addr2);
    else if (ctx->MODULO()) {
      std::string temp1 = "%"+codeCounters.newTEMP();
      std::string temp2 = "%"+codeCounters.newTEMP();

      code = code || instruction::DIV(temp1, addr1, addr2)
                  || instruction::MUL(temp2, temp1, addr2)
                  || instruction::SUB(temp,  addr1, temp2);
    }
    else if (ctx->PLUS()) code = code || instruction::ADD(temp, addr1, addr2);
    else code = code || instruction::SUB(temp, addr1, addr2);
  }

  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

std::any CodeGenVisitor::visitRelational(AslParser::RelationalContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = std::any_cast<CodeAttribs>(visit(ctx->expr(0)));
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  CodeAttribs     && codAt2 = std::any_cast<CodeAttribs>(visit(ctx->expr(1)));
  std::string         addr2 = codAt2.addr;
  instructionList &   code2 = codAt2.code;
  instructionList &&   code = code1 || code2;
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));

  std::string temp = "%"+codeCounters.newTEMP();
  std::string tempAux = "%"+codeCounters.newTEMP();

  if (Types.isFloatTy(t1) or Types.isFloatTy(t2)) {
    std::string temp1 = "%"+codeCounters.newTEMP();
    std::string temp2 = "%"+codeCounters.newTEMP();

    if (Types.isIntegerTy(t1)) code = code || instruction::FLOAT(temp1,addr1);
    else temp1 = addr1;
    if (Types.isIntegerTy(t2)) code = code || instruction::FLOAT(temp2,addr2);
    else temp2 = addr2;

    if (ctx->EQUAL()) code = code || instruction::FEQ(temp, temp1, temp2);
    else if (ctx->NE()) {
      code = code || instruction::FEQ(tempAux, temp1, temp2);
      code = code || instruction::NOT(temp,tempAux);
    }
    else if (ctx->GT()) {
      code = code || instruction::FLE(tempAux, temp1, temp2);
      code = code = code || instruction::NOT(temp,tempAux);
    }
    else if (ctx->GE()) {
      code = code || instruction::FLT(tempAux, temp1, temp2);
      code = code = code || instruction::NOT(temp,tempAux);
    }
    else if (ctx->LT()) code = code || instruction::FLT(temp, temp1, temp2);
    else code = code || instruction::FLE(temp, temp1, temp2);
  }
  else{
    if (ctx->EQUAL()) code = code || instruction::EQ(temp, addr1, addr2);
    else if (ctx->NE()) {
      code = code || instruction::EQ(tempAux, addr1, addr2);
      code = code || instruction::NOT(temp,tempAux);
    }
    else if (ctx->GT()) {
      code = code || instruction::LE(tempAux, addr1, addr2);
      code = code = code || instruction::NOT(temp,tempAux);
    }
    else if (ctx->GE()) {
      code = code || instruction::LT(tempAux, addr1, addr2);
      code = code = code || instruction::NOT(temp,tempAux);
    }
    else if (ctx->LT()) code = code || instruction::LT(temp, addr1, addr2);
    else code = code || instruction::LE(temp, addr1, addr2);
  }
  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

std::any CodeGenVisitor::visitLogical(AslParser::LogicalContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = std::any_cast<CodeAttribs>(visit(ctx->expr(0)));
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  CodeAttribs     && codAt2 = std::any_cast<CodeAttribs>(visit(ctx->expr(1)));
  std::string         addr2 = codAt2.addr;
  instructionList &   code2 = codAt2.code;
  instructionList &&   code = code1 || code2;

  std::string temp = "%"+codeCounters.newTEMP();

  if (ctx->AND()) code = code || instruction::AND(temp, addr1, addr2);
  else code = code || instruction::OR(temp, addr1, addr2);

  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

std::any CodeGenVisitor::visitValue(AslParser::ValueContext *ctx) {
  // ch
  // f
  // i
  // bool
  DEBUG_ENTER();
  instructionList code;
  std::string temp = "%"+codeCounters.newTEMP();

  if (ctx->INTVAL()) code = instruction::ILOAD(temp, ctx->getText());
  else if (ctx->FLOATVAL()) code = instruction::FLOAD(temp, ctx->getText());
  else if (ctx->CHARVAL()) code = instruction::LOAD(temp, ctx->getText());
  else {
    if (ctx->TRUEVAL()) code = instruction::ILOAD(temp, "1");
    else code = instruction::ILOAD(temp, "0");
  }

  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

std::any CodeGenVisitor::visitExprIdent(AslParser::ExprIdentContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs && codAts = std::any_cast<CodeAttribs>(visit(ctx->ident()));
  DEBUG_EXIT();
  return codAts;
}

std::any CodeGenVisitor::visitIdent(AslParser::IdentContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs codAts(ctx->ID()->getText(), "", instructionList());
  DEBUG_EXIT();
  return codAts;
}

// Getters for the necessary tree node atributes:
//   Scope and Type
SymTable::ScopeId CodeGenVisitor::getScopeDecor(antlr4::ParserRuleContext *ctx) const {
  return Decorations.getScope(ctx);
}

TypesMgr::TypeId CodeGenVisitor::getTypeDecor(antlr4::ParserRuleContext *ctx) const {
  return Decorations.getType(ctx);
}


// Constructors of the class CodeAttribs:
//
CodeGenVisitor::CodeAttribs::CodeAttribs(const std::string & addr,
                                         const std::string & offs,
                                         instructionList & code) :
  addr{addr}, offs{offs}, code{code} {
}

CodeGenVisitor::CodeAttribs::CodeAttribs(const std::string & addr,
                                         const std::string & offs,
                                         instructionList && code) :
  addr{addr}, offs{offs}, code{code} {
}
