
// Generated from Asl.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, ASSIGN = 5, EQUAL = 6, NE = 7, 
    GT = 8, GE = 9, LT = 10, LE = 11, PLUS = 12, MINUS = 13, DIV = 14, MUL = 15, 
    VAR = 16, INT = 17, FLOAT = 18, BOOL = 19, CHAR = 20, IF = 21, THEN = 22, 
    ELSE = 23, ENDIF = 24, FUNC = 25, ENDFUNC = 26, READ = 27, WRITE = 28, 
    AND = 29, OR = 30, NOT = 31, ID = 32, INTVAL = 33, BOOLVAL = 34, FLOATVAL = 35, 
    CHARVAL = 36, STRING = 37, COMMENT = 38, WS = 39
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

