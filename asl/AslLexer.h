
// Generated from Asl.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    ASSIGN = 8, EQUAL = 9, NE = 10, GT = 11, GE = 12, LT = 13, LE = 14, 
    PLUS = 15, MINUS = 16, DIV = 17, MUL = 18, VAR = 19, INT = 20, FLOAT = 21, 
    BOOL = 22, CHAR = 23, IF = 24, THEN = 25, ELSE = 26, ENDIF = 27, WHILE = 28, 
    DO = 29, ENDWHILE = 30, FUNC = 31, ENDFUNC = 32, READ = 33, WRITE = 34, 
    RETURN = 35, AND = 36, OR = 37, NOT = 38, INTVAL = 39, BOOLVAL = 40, 
    FLOATVAL = 41, CHARVAL = 42, ID = 43, STRING = 44, COMMENT = 45, WS = 46
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

