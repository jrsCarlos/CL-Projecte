
// Generated from Asl.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, ASSIGN = 6, EQUAL = 7, 
    NE = 8, GT = 9, GE = 10, LT = 11, LE = 12, PLUS = 13, MINUS = 14, DIV = 15, 
    MUL = 16, VAR = 17, INT = 18, FLOAT = 19, BOOL = 20, CHAR = 21, IF = 22, 
    THEN = 23, ELSE = 24, ENDIF = 25, WHILE = 26, DO = 27, ENDWHILE = 28, 
    FUNC = 29, ENDFUNC = 30, READ = 31, WRITE = 32, RETURN = 33, AND = 34, 
    OR = 35, NOT = 36, INTVAL = 37, BOOLVAL = 38, FLOATVAL = 39, CHARVAL = 40, 
    ID = 41, STRING = 42, COMMENT = 43, WS = 44
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

