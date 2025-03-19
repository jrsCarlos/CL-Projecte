
// Generated from Asl.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    ASSIGN = 8, EQUAL = 9, NE = 10, GT = 11, GE = 12, LT = 13, LE = 14, 
    PLUS = 15, MINUS = 16, DIV = 17, MUL = 18, VAR = 19, ARRAY = 20, OF = 21, 
    INT = 22, FLOAT = 23, BOOL = 24, CHAR = 25, IF = 26, THEN = 27, ELSE = 28, 
    ENDIF = 29, WHILE = 30, DO = 31, ENDWHILE = 32, FUNC = 33, ENDFUNC = 34, 
    READ = 35, WRITE = 36, RETURN = 37, AND = 38, OR = 39, NOT = 40, INTVAL = 41, 
    BOOLVAL = 42, FLOATVAL = 43, CHARVAL = 44, ID = 45, STRING = 46, COMMENT = 47, 
    WS = 48
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

