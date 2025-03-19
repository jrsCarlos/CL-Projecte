
// Generated from Asl.g4 by ANTLR 4.13.2


#include "AslVisitor.h"

#include "AslParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct AslParserStaticData final {
  AslParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  AslParserStaticData(const AslParserStaticData&) = delete;
  AslParserStaticData(AslParserStaticData&&) = delete;
  AslParserStaticData& operator=(const AslParserStaticData&) = delete;
  AslParserStaticData& operator=(AslParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag aslParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<AslParserStaticData> aslParserStaticData = nullptr;

void aslParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (aslParserStaticData != nullptr) {
    return;
  }
#else
  assert(aslParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<AslParserStaticData>(
    std::vector<std::string>{
      "program", "function", "parameters", "parameter", "declarations", 
      "variable_decl", "type", "basicType", "statements", "statement", "left_expr", 
      "expr", "ident"
    },
    std::vector<std::string>{
      "", "'('", "')'", "':'", "','", "'['", "']'", "';'", "'='", "'=='", 
      "'!='", "'>'", "'>='", "'<'", "'<='", "'+'", "'-'", "'/'", "'*'", 
      "'var'", "'array'", "'of'", "'int'", "'float'", "'bool'", "'char'", 
      "'if'", "'then'", "'else'", "'endif'", "'while'", "'do'", "'endwhile'", 
      "'func'", "'endfunc'", "'read'", "'write'", "'return'", "'and'", "'or'", 
      "'not'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "ASSIGN", "EQUAL", "NE", "GT", "GE", 
      "LT", "LE", "PLUS", "MINUS", "DIV", "MUL", "VAR", "ARRAY", "OF", "INT", 
      "FLOAT", "BOOL", "CHAR", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", 
      "ENDWHILE", "FUNC", "ENDFUNC", "READ", "WRITE", "RETURN", "AND", "OR", 
      "NOT", "INTVAL", "BOOLVAL", "FLOATVAL", "CHARVAL", "ID", "STRING", 
      "COMMENT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,48,213,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,1,0,4,0,28,8,0,11,
  	0,12,0,29,1,0,1,0,1,1,1,1,1,1,1,1,3,1,38,8,1,1,1,1,1,1,1,3,1,43,8,1,1,
  	1,1,1,1,1,1,1,1,2,1,2,1,2,5,2,52,8,2,10,2,12,2,55,9,2,1,3,1,3,1,3,1,3,
  	1,4,5,4,62,8,4,10,4,12,4,65,9,4,1,5,1,5,1,5,1,5,5,5,71,8,5,10,5,12,5,
  	74,9,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,86,8,6,1,7,1,7,1,8,
  	5,8,91,8,8,10,8,12,8,94,9,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,3,9,107,8,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,5,9,
  	122,8,9,10,9,12,9,125,9,9,3,9,127,8,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,
  	1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,3,9,145,8,9,1,9,3,9,148,8,9,1,10,1,10,
  	1,10,1,10,1,10,1,10,3,10,156,8,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,5,11,176,8,11,
  	10,11,12,11,179,9,11,3,11,181,8,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,
  	189,8,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,5,11,206,8,11,10,11,12,11,209,9,11,1,12,1,12,1,12,0,1,
  	22,13,0,2,4,6,8,10,12,14,16,18,20,22,24,0,5,1,0,22,25,2,0,15,16,40,40,
  	1,0,17,18,1,0,15,16,1,0,9,14,234,0,27,1,0,0,0,2,33,1,0,0,0,4,48,1,0,0,
  	0,6,56,1,0,0,0,8,63,1,0,0,0,10,66,1,0,0,0,12,85,1,0,0,0,14,87,1,0,0,0,
  	16,92,1,0,0,0,18,147,1,0,0,0,20,155,1,0,0,0,22,188,1,0,0,0,24,210,1,0,
  	0,0,26,28,3,2,1,0,27,26,1,0,0,0,28,29,1,0,0,0,29,27,1,0,0,0,29,30,1,0,
  	0,0,30,31,1,0,0,0,31,32,5,0,0,1,32,1,1,0,0,0,33,34,5,33,0,0,34,35,5,45,
  	0,0,35,37,5,1,0,0,36,38,3,4,2,0,37,36,1,0,0,0,37,38,1,0,0,0,38,39,1,0,
  	0,0,39,42,5,2,0,0,40,41,5,3,0,0,41,43,3,12,6,0,42,40,1,0,0,0,42,43,1,
  	0,0,0,43,44,1,0,0,0,44,45,3,8,4,0,45,46,3,16,8,0,46,47,5,34,0,0,47,3,
  	1,0,0,0,48,53,3,6,3,0,49,50,5,4,0,0,50,52,3,6,3,0,51,49,1,0,0,0,52,55,
  	1,0,0,0,53,51,1,0,0,0,53,54,1,0,0,0,54,5,1,0,0,0,55,53,1,0,0,0,56,57,
  	5,45,0,0,57,58,5,3,0,0,58,59,3,12,6,0,59,7,1,0,0,0,60,62,3,10,5,0,61,
  	60,1,0,0,0,62,65,1,0,0,0,63,61,1,0,0,0,63,64,1,0,0,0,64,9,1,0,0,0,65,
  	63,1,0,0,0,66,67,5,19,0,0,67,72,5,45,0,0,68,69,5,4,0,0,69,71,5,45,0,0,
  	70,68,1,0,0,0,71,74,1,0,0,0,72,70,1,0,0,0,72,73,1,0,0,0,73,75,1,0,0,0,
  	74,72,1,0,0,0,75,76,5,3,0,0,76,77,3,12,6,0,77,11,1,0,0,0,78,79,5,20,0,
  	0,79,80,5,5,0,0,80,81,5,41,0,0,81,82,5,6,0,0,82,83,5,21,0,0,83,86,3,14,
  	7,0,84,86,3,14,7,0,85,78,1,0,0,0,85,84,1,0,0,0,86,13,1,0,0,0,87,88,7,
  	0,0,0,88,15,1,0,0,0,89,91,3,18,9,0,90,89,1,0,0,0,91,94,1,0,0,0,92,90,
  	1,0,0,0,92,93,1,0,0,0,93,17,1,0,0,0,94,92,1,0,0,0,95,96,3,20,10,0,96,
  	97,5,8,0,0,97,98,3,22,11,0,98,99,5,7,0,0,99,148,1,0,0,0,100,101,5,26,
  	0,0,101,102,3,22,11,0,102,103,5,27,0,0,103,106,3,16,8,0,104,105,5,28,
  	0,0,105,107,3,16,8,0,106,104,1,0,0,0,106,107,1,0,0,0,107,108,1,0,0,0,
  	108,109,5,29,0,0,109,148,1,0,0,0,110,111,5,30,0,0,111,112,3,22,11,0,112,
  	113,5,31,0,0,113,114,3,16,8,0,114,115,5,32,0,0,115,148,1,0,0,0,116,117,
  	3,24,12,0,117,126,5,1,0,0,118,123,3,22,11,0,119,120,5,4,0,0,120,122,3,
  	22,11,0,121,119,1,0,0,0,122,125,1,0,0,0,123,121,1,0,0,0,123,124,1,0,0,
  	0,124,127,1,0,0,0,125,123,1,0,0,0,126,118,1,0,0,0,126,127,1,0,0,0,127,
  	128,1,0,0,0,128,129,5,2,0,0,129,130,5,7,0,0,130,148,1,0,0,0,131,132,5,
  	35,0,0,132,133,3,20,10,0,133,134,5,7,0,0,134,148,1,0,0,0,135,136,5,36,
  	0,0,136,137,3,22,11,0,137,138,5,7,0,0,138,148,1,0,0,0,139,140,5,36,0,
  	0,140,141,5,46,0,0,141,148,5,7,0,0,142,144,5,37,0,0,143,145,3,22,11,0,
  	144,143,1,0,0,0,144,145,1,0,0,0,145,146,1,0,0,0,146,148,5,7,0,0,147,95,
  	1,0,0,0,147,100,1,0,0,0,147,110,1,0,0,0,147,116,1,0,0,0,147,131,1,0,0,
  	0,147,135,1,0,0,0,147,139,1,0,0,0,147,142,1,0,0,0,148,19,1,0,0,0,149,
  	156,3,24,12,0,150,151,3,24,12,0,151,152,5,5,0,0,152,153,3,22,11,0,153,
  	154,5,6,0,0,154,156,1,0,0,0,155,149,1,0,0,0,155,150,1,0,0,0,156,21,1,
  	0,0,0,157,158,6,11,-1,0,158,159,7,1,0,0,159,189,3,22,11,14,160,189,5,
  	41,0,0,161,189,5,43,0,0,162,189,5,44,0,0,163,189,5,42,0,0,164,189,3,24,
  	12,0,165,166,3,24,12,0,166,167,5,5,0,0,167,168,3,22,11,0,168,169,5,6,
  	0,0,169,189,1,0,0,0,170,171,3,24,12,0,171,180,5,1,0,0,172,177,3,22,11,
  	0,173,174,5,4,0,0,174,176,3,22,11,0,175,173,1,0,0,0,176,179,1,0,0,0,177,
  	175,1,0,0,0,177,178,1,0,0,0,178,181,1,0,0,0,179,177,1,0,0,0,180,172,1,
  	0,0,0,180,181,1,0,0,0,181,182,1,0,0,0,182,183,5,2,0,0,183,189,1,0,0,0,
  	184,185,5,1,0,0,185,186,3,22,11,0,186,187,5,2,0,0,187,189,1,0,0,0,188,
  	157,1,0,0,0,188,160,1,0,0,0,188,161,1,0,0,0,188,162,1,0,0,0,188,163,1,
  	0,0,0,188,164,1,0,0,0,188,165,1,0,0,0,188,170,1,0,0,0,188,184,1,0,0,0,
  	189,207,1,0,0,0,190,191,10,13,0,0,191,192,7,2,0,0,192,206,3,22,11,14,
  	193,194,10,12,0,0,194,195,7,3,0,0,195,206,3,22,11,13,196,197,10,11,0,
  	0,197,198,7,4,0,0,198,206,3,22,11,12,199,200,10,10,0,0,200,201,5,38,0,
  	0,201,206,3,22,11,11,202,203,10,9,0,0,203,204,5,39,0,0,204,206,3,22,11,
  	10,205,190,1,0,0,0,205,193,1,0,0,0,205,196,1,0,0,0,205,199,1,0,0,0,205,
  	202,1,0,0,0,206,209,1,0,0,0,207,205,1,0,0,0,207,208,1,0,0,0,208,23,1,
  	0,0,0,209,207,1,0,0,0,210,211,5,45,0,0,211,25,1,0,0,0,19,29,37,42,53,
  	63,72,85,92,106,123,126,144,147,155,177,180,188,205,207
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  aslParserStaticData = std::move(staticData);
}

}

AslParser::AslParser(TokenStream *input) : AslParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

AslParser::AslParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  AslParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *aslParserStaticData->atn, aslParserStaticData->decisionToDFA, aslParserStaticData->sharedContextCache, options);
}

AslParser::~AslParser() {
  delete _interpreter;
}

const atn::ATN& AslParser::getATN() const {
  return *aslParserStaticData->atn;
}

std::string AslParser::getGrammarFileName() const {
  return "Asl.g4";
}

const std::vector<std::string>& AslParser::getRuleNames() const {
  return aslParserStaticData->ruleNames;
}

const dfa::Vocabulary& AslParser::getVocabulary() const {
  return aslParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView AslParser::getSerializedATN() const {
  return aslParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

AslParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::ProgramContext::EOF() {
  return getToken(AslParser::EOF, 0);
}

std::vector<AslParser::FunctionContext *> AslParser::ProgramContext::function() {
  return getRuleContexts<AslParser::FunctionContext>();
}

AslParser::FunctionContext* AslParser::ProgramContext::function(size_t i) {
  return getRuleContext<AslParser::FunctionContext>(i);
}


size_t AslParser::ProgramContext::getRuleIndex() const {
  return AslParser::RuleProgram;
}


std::any AslParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

AslParser::ProgramContext* AslParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, AslParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(27); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(26);
      function();
      setState(29); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == AslParser::FUNC);
    setState(31);
    match(AslParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

AslParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::FunctionContext::FUNC() {
  return getToken(AslParser::FUNC, 0);
}

tree::TerminalNode* AslParser::FunctionContext::ID() {
  return getToken(AslParser::ID, 0);
}

AslParser::DeclarationsContext* AslParser::FunctionContext::declarations() {
  return getRuleContext<AslParser::DeclarationsContext>(0);
}

AslParser::StatementsContext* AslParser::FunctionContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}

tree::TerminalNode* AslParser::FunctionContext::ENDFUNC() {
  return getToken(AslParser::ENDFUNC, 0);
}

AslParser::ParametersContext* AslParser::FunctionContext::parameters() {
  return getRuleContext<AslParser::ParametersContext>(0);
}

AslParser::TypeContext* AslParser::FunctionContext::type() {
  return getRuleContext<AslParser::TypeContext>(0);
}


size_t AslParser::FunctionContext::getRuleIndex() const {
  return AslParser::RuleFunction;
}


std::any AslParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

AslParser::FunctionContext* AslParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 2, AslParser::RuleFunction);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(33);
    match(AslParser::FUNC);
    setState(34);
    match(AslParser::ID);
    setState(35);
    match(AslParser::T__0);
    setState(37);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AslParser::ID) {
      setState(36);
      parameters();
    }
    setState(39);
    match(AslParser::T__1);
    setState(42);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AslParser::T__2) {
      setState(40);
      match(AslParser::T__2);
      setState(41);
      type();
    }
    setState(44);
    declarations();
    setState(45);
    statements();
    setState(46);
    match(AslParser::ENDFUNC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

AslParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::ParameterContext *> AslParser::ParametersContext::parameter() {
  return getRuleContexts<AslParser::ParameterContext>();
}

AslParser::ParameterContext* AslParser::ParametersContext::parameter(size_t i) {
  return getRuleContext<AslParser::ParameterContext>(i);
}


size_t AslParser::ParametersContext::getRuleIndex() const {
  return AslParser::RuleParameters;
}


std::any AslParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

AslParser::ParametersContext* AslParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 4, AslParser::RuleParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    parameter();
    setState(53);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::T__3) {
      setState(49);
      match(AslParser::T__3);
      setState(50);
      parameter();
      setState(55);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

AslParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::ParameterContext::ID() {
  return getToken(AslParser::ID, 0);
}

AslParser::TypeContext* AslParser::ParameterContext::type() {
  return getRuleContext<AslParser::TypeContext>(0);
}


size_t AslParser::ParameterContext::getRuleIndex() const {
  return AslParser::RuleParameter;
}


std::any AslParser::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitParameter(this);
  else
    return visitor->visitChildren(this);
}

AslParser::ParameterContext* AslParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 6, AslParser::RuleParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(56);
    match(AslParser::ID);
    setState(57);
    match(AslParser::T__2);
    setState(58);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

AslParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::Variable_declContext *> AslParser::DeclarationsContext::variable_decl() {
  return getRuleContexts<AslParser::Variable_declContext>();
}

AslParser::Variable_declContext* AslParser::DeclarationsContext::variable_decl(size_t i) {
  return getRuleContext<AslParser::Variable_declContext>(i);
}


size_t AslParser::DeclarationsContext::getRuleIndex() const {
  return AslParser::RuleDeclarations;
}


std::any AslParser::DeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitDeclarations(this);
  else
    return visitor->visitChildren(this);
}

AslParser::DeclarationsContext* AslParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 8, AslParser::RuleDeclarations);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(63);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::VAR) {
      setState(60);
      variable_decl();
      setState(65);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_declContext ------------------------------------------------------------------

AslParser::Variable_declContext::Variable_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::Variable_declContext::VAR() {
  return getToken(AslParser::VAR, 0);
}

std::vector<tree::TerminalNode *> AslParser::Variable_declContext::ID() {
  return getTokens(AslParser::ID);
}

tree::TerminalNode* AslParser::Variable_declContext::ID(size_t i) {
  return getToken(AslParser::ID, i);
}

AslParser::TypeContext* AslParser::Variable_declContext::type() {
  return getRuleContext<AslParser::TypeContext>(0);
}


size_t AslParser::Variable_declContext::getRuleIndex() const {
  return AslParser::RuleVariable_decl;
}


std::any AslParser::Variable_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitVariable_decl(this);
  else
    return visitor->visitChildren(this);
}

AslParser::Variable_declContext* AslParser::variable_decl() {
  Variable_declContext *_localctx = _tracker.createInstance<Variable_declContext>(_ctx, getState());
  enterRule(_localctx, 10, AslParser::RuleVariable_decl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    match(AslParser::VAR);
    setState(67);
    match(AslParser::ID);
    setState(72);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::T__3) {
      setState(68);
      match(AslParser::T__3);
      setState(69);
      match(AslParser::ID);
      setState(74);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(75);
    match(AslParser::T__2);
    setState(76);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

AslParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::TypeContext::ARRAY() {
  return getToken(AslParser::ARRAY, 0);
}

tree::TerminalNode* AslParser::TypeContext::INTVAL() {
  return getToken(AslParser::INTVAL, 0);
}

tree::TerminalNode* AslParser::TypeContext::OF() {
  return getToken(AslParser::OF, 0);
}

AslParser::BasicTypeContext* AslParser::TypeContext::basicType() {
  return getRuleContext<AslParser::BasicTypeContext>(0);
}


size_t AslParser::TypeContext::getRuleIndex() const {
  return AslParser::RuleType;
}


std::any AslParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

AslParser::TypeContext* AslParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 12, AslParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(85);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AslParser::ARRAY: {
        enterOuterAlt(_localctx, 1);
        setState(78);
        match(AslParser::ARRAY);
        setState(79);
        match(AslParser::T__4);
        setState(80);
        match(AslParser::INTVAL);
        setState(81);
        match(AslParser::T__5);
        setState(82);
        match(AslParser::OF);
        setState(83);
        basicType();
        break;
      }

      case AslParser::INT:
      case AslParser::FLOAT:
      case AslParser::BOOL:
      case AslParser::CHAR: {
        enterOuterAlt(_localctx, 2);
        setState(84);
        basicType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BasicTypeContext ------------------------------------------------------------------

AslParser::BasicTypeContext::BasicTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::BasicTypeContext::INT() {
  return getToken(AslParser::INT, 0);
}

tree::TerminalNode* AslParser::BasicTypeContext::FLOAT() {
  return getToken(AslParser::FLOAT, 0);
}

tree::TerminalNode* AslParser::BasicTypeContext::BOOL() {
  return getToken(AslParser::BOOL, 0);
}

tree::TerminalNode* AslParser::BasicTypeContext::CHAR() {
  return getToken(AslParser::CHAR, 0);
}


size_t AslParser::BasicTypeContext::getRuleIndex() const {
  return AslParser::RuleBasicType;
}


std::any AslParser::BasicTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitBasicType(this);
  else
    return visitor->visitChildren(this);
}

AslParser::BasicTypeContext* AslParser::basicType() {
  BasicTypeContext *_localctx = _tracker.createInstance<BasicTypeContext>(_ctx, getState());
  enterRule(_localctx, 14, AslParser::RuleBasicType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 62914560) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

AslParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::StatementContext *> AslParser::StatementsContext::statement() {
  return getRuleContexts<AslParser::StatementContext>();
}

AslParser::StatementContext* AslParser::StatementsContext::statement(size_t i) {
  return getRuleContext<AslParser::StatementContext>(i);
}


size_t AslParser::StatementsContext::getRuleIndex() const {
  return AslParser::RuleStatements;
}


std::any AslParser::StatementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitStatements(this);
  else
    return visitor->visitChildren(this);
}

AslParser::StatementsContext* AslParser::statements() {
  StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, getState());
  enterRule(_localctx, 16, AslParser::RuleStatements);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 35426031108096) != 0)) {
      setState(89);
      statement();
      setState(94);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

AslParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::StatementContext::getRuleIndex() const {
  return AslParser::RuleStatement;
}

void AslParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ProcCallContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ProcCallContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

std::vector<AslParser::ExprContext *> AslParser::ProcCallContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::ProcCallContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

AslParser::ProcCallContext::ProcCallContext(StatementContext *ctx) { copyFrom(ctx); }


std::any AslParser::ProcCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitProcCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WriteExprContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WriteExprContext::WRITE() {
  return getToken(AslParser::WRITE, 0);
}

AslParser::ExprContext* AslParser::WriteExprContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::WriteExprContext::WriteExprContext(StatementContext *ctx) { copyFrom(ctx); }


std::any AslParser::WriteExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitWriteExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WhileStmtContext::WHILE() {
  return getToken(AslParser::WHILE, 0);
}

AslParser::ExprContext* AslParser::WhileStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::WhileStmtContext::DO() {
  return getToken(AslParser::DO, 0);
}

AslParser::StatementsContext* AslParser::WhileStmtContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}

tree::TerminalNode* AslParser::WhileStmtContext::ENDWHILE() {
  return getToken(AslParser::ENDWHILE, 0);
}

AslParser::WhileStmtContext::WhileStmtContext(StatementContext *ctx) { copyFrom(ctx); }


std::any AslParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::IfStmtContext::IF() {
  return getToken(AslParser::IF, 0);
}

AslParser::ExprContext* AslParser::IfStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::IfStmtContext::THEN() {
  return getToken(AslParser::THEN, 0);
}

std::vector<AslParser::StatementsContext *> AslParser::IfStmtContext::statements() {
  return getRuleContexts<AslParser::StatementsContext>();
}

AslParser::StatementsContext* AslParser::IfStmtContext::statements(size_t i) {
  return getRuleContext<AslParser::StatementsContext>(i);
}

tree::TerminalNode* AslParser::IfStmtContext::ENDIF() {
  return getToken(AslParser::ENDIF, 0);
}

tree::TerminalNode* AslParser::IfStmtContext::ELSE() {
  return getToken(AslParser::ELSE, 0);
}

AslParser::IfStmtContext::IfStmtContext(StatementContext *ctx) { copyFrom(ctx); }


std::any AslParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReadStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ReadStmtContext::READ() {
  return getToken(AslParser::READ, 0);
}

AslParser::Left_exprContext* AslParser::ReadStmtContext::left_expr() {
  return getRuleContext<AslParser::Left_exprContext>(0);
}

AslParser::ReadStmtContext::ReadStmtContext(StatementContext *ctx) { copyFrom(ctx); }


std::any AslParser::ReadStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitReadStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignStmtContext ------------------------------------------------------------------

AslParser::Left_exprContext* AslParser::AssignStmtContext::left_expr() {
  return getRuleContext<AslParser::Left_exprContext>(0);
}

tree::TerminalNode* AslParser::AssignStmtContext::ASSIGN() {
  return getToken(AslParser::ASSIGN, 0);
}

AslParser::ExprContext* AslParser::AssignStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::AssignStmtContext::AssignStmtContext(StatementContext *ctx) { copyFrom(ctx); }


std::any AslParser::AssignStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitAssignStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ReturnStmtContext::RETURN() {
  return getToken(AslParser::RETURN, 0);
}

AslParser::ExprContext* AslParser::ReturnStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::ReturnStmtContext::ReturnStmtContext(StatementContext *ctx) { copyFrom(ctx); }


std::any AslParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WriteStringContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WriteStringContext::WRITE() {
  return getToken(AslParser::WRITE, 0);
}

tree::TerminalNode* AslParser::WriteStringContext::STRING() {
  return getToken(AslParser::STRING, 0);
}

AslParser::WriteStringContext::WriteStringContext(StatementContext *ctx) { copyFrom(ctx); }


std::any AslParser::WriteStringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitWriteString(this);
  else
    return visitor->visitChildren(this);
}
AslParser::StatementContext* AslParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 18, AslParser::RuleStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(147);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<AslParser::AssignStmtContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(95);
      left_expr();
      setState(96);
      match(AslParser::ASSIGN);
      setState(97);
      expr(0);
      setState(98);
      match(AslParser::T__6);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<AslParser::IfStmtContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(100);
      match(AslParser::IF);
      setState(101);
      expr(0);
      setState(102);
      match(AslParser::THEN);
      setState(103);
      statements();
      setState(106);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == AslParser::ELSE) {
        setState(104);
        match(AslParser::ELSE);
        setState(105);
        statements();
      }
      setState(108);
      match(AslParser::ENDIF);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<AslParser::WhileStmtContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(110);
      match(AslParser::WHILE);
      setState(111);
      expr(0);
      setState(112);
      match(AslParser::DO);
      setState(113);
      statements();
      setState(114);
      match(AslParser::ENDWHILE);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<AslParser::ProcCallContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(116);
      ident();
      setState(117);
      match(AslParser::T__0);
      setState(126);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 69269232648194) != 0)) {
        setState(118);
        expr(0);
        setState(123);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == AslParser::T__3) {
          setState(119);
          match(AslParser::T__3);
          setState(120);
          expr(0);
          setState(125);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(128);
      match(AslParser::T__1);
      setState(129);
      match(AslParser::T__6);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<AslParser::ReadStmtContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(131);
      match(AslParser::READ);
      setState(132);
      left_expr();
      setState(133);
      match(AslParser::T__6);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<AslParser::WriteExprContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(135);
      match(AslParser::WRITE);
      setState(136);
      expr(0);
      setState(137);
      match(AslParser::T__6);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<AslParser::WriteStringContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(139);
      match(AslParser::WRITE);
      setState(140);
      match(AslParser::STRING);
      setState(141);
      match(AslParser::T__6);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<AslParser::ReturnStmtContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(142);
      match(AslParser::RETURN);
      setState(144);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 69269232648194) != 0)) {
        setState(143);
        expr(0);
      }
      setState(146);
      match(AslParser::T__6);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Left_exprContext ------------------------------------------------------------------

AslParser::Left_exprContext::Left_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AslParser::IdentContext* AslParser::Left_exprContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::ExprContext* AslParser::Left_exprContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}


size_t AslParser::Left_exprContext::getRuleIndex() const {
  return AslParser::RuleLeft_expr;
}


std::any AslParser::Left_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitLeft_expr(this);
  else
    return visitor->visitChildren(this);
}

AslParser::Left_exprContext* AslParser::left_expr() {
  Left_exprContext *_localctx = _tracker.createInstance<Left_exprContext>(_ctx, getState());
  enterRule(_localctx, 20, AslParser::RuleLeft_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(155);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(149);
      ident();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(150);
      ident();
      setState(151);
      match(AslParser::T__4);
      setState(152);
      expr(0);
      setState(153);
      match(AslParser::T__5);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

AslParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::ExprContext::getRuleIndex() const {
  return AslParser::RuleExpr;
}

void AslParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParentContext ------------------------------------------------------------------

AslParser::ExprContext* AslParser::ParentContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::ParentContext::ParentContext(ExprContext *ctx) { copyFrom(ctx); }


std::any AslParser::ParentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitParent(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprIdentContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ExprIdentContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::ExprIdentContext::ExprIdentContext(ExprContext *ctx) { copyFrom(ctx); }


std::any AslParser::ExprIdentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitExprIdent(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArithmeticContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::ArithmeticContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::ArithmeticContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::ArithmeticContext::MUL() {
  return getToken(AslParser::MUL, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::DIV() {
  return getToken(AslParser::DIV, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::PLUS() {
  return getToken(AslParser::PLUS, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::MINUS() {
  return getToken(AslParser::MINUS, 0);
}

AslParser::ArithmeticContext::ArithmeticContext(ExprContext *ctx) { copyFrom(ctx); }


std::any AslParser::ArithmeticContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitArithmetic(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RelationalContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::RelationalContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::RelationalContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::RelationalContext::EQUAL() {
  return getToken(AslParser::EQUAL, 0);
}

tree::TerminalNode* AslParser::RelationalContext::NE() {
  return getToken(AslParser::NE, 0);
}

tree::TerminalNode* AslParser::RelationalContext::GT() {
  return getToken(AslParser::GT, 0);
}

tree::TerminalNode* AslParser::RelationalContext::GE() {
  return getToken(AslParser::GE, 0);
}

tree::TerminalNode* AslParser::RelationalContext::LT() {
  return getToken(AslParser::LT, 0);
}

tree::TerminalNode* AslParser::RelationalContext::LE() {
  return getToken(AslParser::LE, 0);
}

AslParser::RelationalContext::RelationalContext(ExprContext *ctx) { copyFrom(ctx); }


std::any AslParser::RelationalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitRelational(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryContext ------------------------------------------------------------------

AslParser::ExprContext* AslParser::UnaryContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::UnaryContext::NOT() {
  return getToken(AslParser::NOT, 0);
}

tree::TerminalNode* AslParser::UnaryContext::PLUS() {
  return getToken(AslParser::PLUS, 0);
}

tree::TerminalNode* AslParser::UnaryContext::MINUS() {
  return getToken(AslParser::MINUS, 0);
}

AslParser::UnaryContext::UnaryContext(ExprContext *ctx) { copyFrom(ctx); }


std::any AslParser::UnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitUnary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FuncCallContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::FuncCallContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

std::vector<AslParser::ExprContext *> AslParser::FuncCallContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::FuncCallContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

AslParser::FuncCallContext::FuncCallContext(ExprContext *ctx) { copyFrom(ctx); }


std::any AslParser::FuncCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitFuncCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprArrayContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ExprArrayContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::ExprContext* AslParser::ExprArrayContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::ExprArrayContext::ExprArrayContext(ExprContext *ctx) { copyFrom(ctx); }


std::any AslParser::ExprArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitExprArray(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ValueContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ValueContext::INTVAL() {
  return getToken(AslParser::INTVAL, 0);
}

tree::TerminalNode* AslParser::ValueContext::FLOATVAL() {
  return getToken(AslParser::FLOATVAL, 0);
}

tree::TerminalNode* AslParser::ValueContext::CHARVAL() {
  return getToken(AslParser::CHARVAL, 0);
}

tree::TerminalNode* AslParser::ValueContext::BOOLVAL() {
  return getToken(AslParser::BOOLVAL, 0);
}

AslParser::ValueContext::ValueContext(ExprContext *ctx) { copyFrom(ctx); }


std::any AslParser::ValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::LogicalContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::LogicalContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::LogicalContext::AND() {
  return getToken(AslParser::AND, 0);
}

tree::TerminalNode* AslParser::LogicalContext::OR() {
  return getToken(AslParser::OR, 0);
}

AslParser::LogicalContext::LogicalContext(ExprContext *ctx) { copyFrom(ctx); }


std::any AslParser::LogicalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitLogical(this);
  else
    return visitor->visitChildren(this);
}

AslParser::ExprContext* AslParser::expr() {
   return expr(0);
}

AslParser::ExprContext* AslParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  AslParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  AslParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, AslParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(188);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<UnaryContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(158);
      antlrcpp::downCast<UnaryContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1099511726080) != 0))) {
        antlrcpp::downCast<UnaryContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(159);
      expr(14);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(160);
      match(AslParser::INTVAL);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(161);
      match(AslParser::FLOATVAL);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(162);
      match(AslParser::CHARVAL);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(163);
      match(AslParser::BOOLVAL);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ExprIdentContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(164);
      ident();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ExprArrayContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(165);
      ident();
      setState(166);
      match(AslParser::T__4);
      setState(167);
      expr(0);
      setState(168);
      match(AslParser::T__5);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<FuncCallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(170);
      ident();
      setState(171);
      match(AslParser::T__0);
      setState(180);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 69269232648194) != 0)) {
        setState(172);
        expr(0);
        setState(177);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == AslParser::T__3) {
          setState(173);
          match(AslParser::T__3);
          setState(174);
          expr(0);
          setState(179);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(182);
      match(AslParser::T__1);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<ParentContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(184);
      match(AslParser::T__0);
      setState(185);
      expr(0);
      setState(186);
      match(AslParser::T__1);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(207);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(205);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(190);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(191);
          antlrcpp::downCast<ArithmeticContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == AslParser::DIV

          || _la == AslParser::MUL)) {
            antlrcpp::downCast<ArithmeticContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(192);
          expr(14);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(193);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(194);
          antlrcpp::downCast<ArithmeticContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == AslParser::PLUS

          || _la == AslParser::MINUS)) {
            antlrcpp::downCast<ArithmeticContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(195);
          expr(13);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<RelationalContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(196);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(197);
          antlrcpp::downCast<RelationalContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 32256) != 0))) {
            antlrcpp::downCast<RelationalContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(198);
          expr(12);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<LogicalContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(199);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(200);
          antlrcpp::downCast<LogicalContext *>(_localctx)->op = match(AslParser::AND);
          setState(201);
          expr(11);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<LogicalContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(202);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(203);
          antlrcpp::downCast<LogicalContext *>(_localctx)->op = match(AslParser::OR);
          setState(204);
          expr(10);
          break;
        }

        default:
          break;
        } 
      }
      setState(209);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- IdentContext ------------------------------------------------------------------

AslParser::IdentContext::IdentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::IdentContext::ID() {
  return getToken(AslParser::ID, 0);
}


size_t AslParser::IdentContext::getRuleIndex() const {
  return AslParser::RuleIdent;
}


std::any AslParser::IdentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitIdent(this);
  else
    return visitor->visitChildren(this);
}

AslParser::IdentContext* AslParser::ident() {
  IdentContext *_localctx = _tracker.createInstance<IdentContext>(_ctx, getState());
  enterRule(_localctx, 24, AslParser::RuleIdent);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(210);
    match(AslParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool AslParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 11: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool AslParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 13);
    case 1: return precpred(_ctx, 12);
    case 2: return precpred(_ctx, 11);
    case 3: return precpred(_ctx, 10);
    case 4: return precpred(_ctx, 9);

  default:
    break;
  }
  return true;
}

void AslParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  aslParserInitialize();
#else
  ::antlr4::internal::call_once(aslParserOnceFlag, aslParserInitialize);
#endif
}
