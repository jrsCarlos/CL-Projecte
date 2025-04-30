
// Generated from Asl.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    ASSIGN = 8, AND = 9, OR = 10, NOT = 11, EQUAL = 12, NE = 13, GT = 14, 
    GE = 15, LT = 16, LE = 17, PLUS = 18, MINUS = 19, DIV = 20, MUL = 21, 
    MODULO = 22, VAR = 23, ARRAY = 24, OF = 25, INT = 26, FLOAT = 27, BOOL = 28, 
    CHAR = 29, IF = 30, THEN = 31, ELSE = 32, ENDIF = 33, WHILE = 34, DO = 35, 
    ENDWHILE = 36, FUNC = 37, ENDFUNC = 38, READ = 39, WRITE = 40, RETURN = 41, 
    INTVAL = 42, TRUEVAL = 43, FALSEVAL = 44, FLOATVAL = 45, CHARVAL = 46, 
    ID = 47, STRING = 48, COMMENT = 49, WS = 50
  };

  explicit AslLexer(antlr4::CharStream *input);

  ~AslLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

