
// Generated from Asl.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    ASSIGN = 8, EQUAL = 9, NE = 10, GT = 11, GE = 12, LT = 13, LE = 14, 
    PLUS = 15, MINUS = 16, DIV = 17, MUL = 18, MODULO = 19, VAR = 20, ARRAY = 21, 
    OF = 22, INT = 23, FLOAT = 24, BOOL = 25, CHAR = 26, IF = 27, THEN = 28, 
    ELSE = 29, ENDIF = 30, WHILE = 31, DO = 32, ENDWHILE = 33, FUNC = 34, 
    ENDFUNC = 35, READ = 36, WRITE = 37, RETURN = 38, AND = 39, OR = 40, 
    NOT = 41, INTVAL = 42, BOOLVAL = 43, FLOATVAL = 44, CHARVAL = 45, ID = 46, 
    STRING = 47, COMMENT = 48, WS = 49
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

