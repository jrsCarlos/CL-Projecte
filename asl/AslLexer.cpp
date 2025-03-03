
// Generated from Asl.g4 by ANTLR 4.13.2


#include "AslLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct AslLexerStaticData final {
  AslLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  AslLexerStaticData(const AslLexerStaticData&) = delete;
  AslLexerStaticData(AslLexerStaticData&&) = delete;
  AslLexerStaticData& operator=(const AslLexerStaticData&) = delete;
  AslLexerStaticData& operator=(AslLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag asllexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<AslLexerStaticData> asllexerLexerStaticData = nullptr;

void asllexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (asllexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(asllexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<AslLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "ASSIGN", "EQUAL", "NE", "GT", "GE", 
      "LT", "LE", "PLUS", "MINUS", "DIV", "MUL", "VAR", "INT", "FLOAT", 
      "BOOL", "CHAR", "IF", "THEN", "ELSE", "ENDIF", "FUNC", "ENDFUNC", 
      "READ", "WRITE", "AND", "OR", "NOT", "ID", "INTVAL", "BOOLVAL", "FLOATVAL", 
      "CHARVAL", "STRING", "ESC_SEQ", "COMMENT", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'('", "')'", "':'", "';'", "'='", "'=='", "'!='", "'>'", "'>='", 
      "'<'", "'<='", "'+'", "'-'", "'/'", "'*'", "'var'", "'int'", "'float'", 
      "'bool'", "'char'", "'if'", "'then'", "'else'", "'endif'", "'func'", 
      "'endfunc'", "'read'", "'write'", "'and'", "'or'", "'not'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "ASSIGN", "EQUAL", "NE", "GT", "GE", "LT", "LE", 
      "PLUS", "MINUS", "DIV", "MUL", "VAR", "INT", "FLOAT", "BOOL", "CHAR", 
      "IF", "THEN", "ELSE", "ENDIF", "FUNC", "ENDFUNC", "READ", "WRITE", 
      "AND", "OR", "NOT", "ID", "INTVAL", "BOOLVAL", "FLOATVAL", "CHARVAL", 
      "STRING", "COMMENT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,39,270,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,1,0,1,0,1,1,1,1,1,2,1,2,
  	1,3,1,3,1,4,1,4,1,5,1,5,1,5,1,6,1,6,1,6,1,7,1,7,1,8,1,8,1,8,1,9,1,9,1,
  	10,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,15,1,15,1,
  	15,1,16,1,16,1,16,1,16,1,17,1,17,1,17,1,17,1,17,1,17,1,18,1,18,1,18,1,
  	18,1,18,1,19,1,19,1,19,1,19,1,19,1,20,1,20,1,20,1,21,1,21,1,21,1,21,1,
  	21,1,22,1,22,1,22,1,22,1,22,1,23,1,23,1,23,1,23,1,23,1,23,1,24,1,24,1,
  	24,1,24,1,24,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,26,1,26,1,26,1,
  	26,1,26,1,27,1,27,1,27,1,27,1,27,1,27,1,28,1,28,1,28,1,28,1,29,1,29,1,
  	29,1,30,1,30,1,30,1,30,1,31,1,31,5,31,196,8,31,10,31,12,31,199,9,31,1,
  	32,4,32,202,8,32,11,32,12,32,203,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,
  	33,1,33,3,33,215,8,33,1,34,4,34,218,8,34,11,34,12,34,219,1,34,1,34,4,
  	34,224,8,34,11,34,12,34,225,1,35,1,35,1,35,3,35,231,8,35,1,35,1,35,1,
  	36,1,36,1,36,5,36,238,8,36,10,36,12,36,241,9,36,1,36,1,36,1,37,1,37,1,
  	37,1,38,1,38,1,38,1,38,5,38,252,8,38,10,38,12,38,255,9,38,1,38,3,38,258,
  	8,38,1,38,1,38,1,38,1,38,1,39,4,39,265,8,39,11,39,12,39,266,1,39,1,39,
  	0,0,40,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,
  	27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,
  	25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,71,36,
  	73,37,75,0,77,38,79,39,1,0,7,2,0,65,90,97,122,4,0,48,57,65,90,95,95,97,
  	122,2,0,39,39,92,92,2,0,34,34,92,92,8,0,34,34,39,39,92,92,98,98,102,102,
  	110,110,114,114,116,116,2,0,10,10,13,13,3,0,9,10,13,13,32,32,279,0,1,
  	1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,
  	0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,
  	1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,
  	0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,
  	0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,
  	1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,
  	0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,77,1,0,0,0,
  	0,79,1,0,0,0,1,81,1,0,0,0,3,83,1,0,0,0,5,85,1,0,0,0,7,87,1,0,0,0,9,89,
  	1,0,0,0,11,91,1,0,0,0,13,94,1,0,0,0,15,97,1,0,0,0,17,99,1,0,0,0,19,102,
  	1,0,0,0,21,104,1,0,0,0,23,107,1,0,0,0,25,109,1,0,0,0,27,111,1,0,0,0,29,
  	113,1,0,0,0,31,115,1,0,0,0,33,119,1,0,0,0,35,123,1,0,0,0,37,129,1,0,0,
  	0,39,134,1,0,0,0,41,139,1,0,0,0,43,142,1,0,0,0,45,147,1,0,0,0,47,152,
  	1,0,0,0,49,158,1,0,0,0,51,163,1,0,0,0,53,171,1,0,0,0,55,176,1,0,0,0,57,
  	182,1,0,0,0,59,186,1,0,0,0,61,189,1,0,0,0,63,193,1,0,0,0,65,201,1,0,0,
  	0,67,214,1,0,0,0,69,217,1,0,0,0,71,227,1,0,0,0,73,234,1,0,0,0,75,244,
  	1,0,0,0,77,247,1,0,0,0,79,264,1,0,0,0,81,82,5,40,0,0,82,2,1,0,0,0,83,
  	84,5,41,0,0,84,4,1,0,0,0,85,86,5,58,0,0,86,6,1,0,0,0,87,88,5,59,0,0,88,
  	8,1,0,0,0,89,90,5,61,0,0,90,10,1,0,0,0,91,92,5,61,0,0,92,93,5,61,0,0,
  	93,12,1,0,0,0,94,95,5,33,0,0,95,96,5,61,0,0,96,14,1,0,0,0,97,98,5,62,
  	0,0,98,16,1,0,0,0,99,100,5,62,0,0,100,101,5,61,0,0,101,18,1,0,0,0,102,
  	103,5,60,0,0,103,20,1,0,0,0,104,105,5,60,0,0,105,106,5,61,0,0,106,22,
  	1,0,0,0,107,108,5,43,0,0,108,24,1,0,0,0,109,110,5,45,0,0,110,26,1,0,0,
  	0,111,112,5,47,0,0,112,28,1,0,0,0,113,114,5,42,0,0,114,30,1,0,0,0,115,
  	116,5,118,0,0,116,117,5,97,0,0,117,118,5,114,0,0,118,32,1,0,0,0,119,120,
  	5,105,0,0,120,121,5,110,0,0,121,122,5,116,0,0,122,34,1,0,0,0,123,124,
  	5,102,0,0,124,125,5,108,0,0,125,126,5,111,0,0,126,127,5,97,0,0,127,128,
  	5,116,0,0,128,36,1,0,0,0,129,130,5,98,0,0,130,131,5,111,0,0,131,132,5,
  	111,0,0,132,133,5,108,0,0,133,38,1,0,0,0,134,135,5,99,0,0,135,136,5,104,
  	0,0,136,137,5,97,0,0,137,138,5,114,0,0,138,40,1,0,0,0,139,140,5,105,0,
  	0,140,141,5,102,0,0,141,42,1,0,0,0,142,143,5,116,0,0,143,144,5,104,0,
  	0,144,145,5,101,0,0,145,146,5,110,0,0,146,44,1,0,0,0,147,148,5,101,0,
  	0,148,149,5,108,0,0,149,150,5,115,0,0,150,151,5,101,0,0,151,46,1,0,0,
  	0,152,153,5,101,0,0,153,154,5,110,0,0,154,155,5,100,0,0,155,156,5,105,
  	0,0,156,157,5,102,0,0,157,48,1,0,0,0,158,159,5,102,0,0,159,160,5,117,
  	0,0,160,161,5,110,0,0,161,162,5,99,0,0,162,50,1,0,0,0,163,164,5,101,0,
  	0,164,165,5,110,0,0,165,166,5,100,0,0,166,167,5,102,0,0,167,168,5,117,
  	0,0,168,169,5,110,0,0,169,170,5,99,0,0,170,52,1,0,0,0,171,172,5,114,0,
  	0,172,173,5,101,0,0,173,174,5,97,0,0,174,175,5,100,0,0,175,54,1,0,0,0,
  	176,177,5,119,0,0,177,178,5,114,0,0,178,179,5,105,0,0,179,180,5,116,0,
  	0,180,181,5,101,0,0,181,56,1,0,0,0,182,183,5,97,0,0,183,184,5,110,0,0,
  	184,185,5,100,0,0,185,58,1,0,0,0,186,187,5,111,0,0,187,188,5,114,0,0,
  	188,60,1,0,0,0,189,190,5,110,0,0,190,191,5,111,0,0,191,192,5,116,0,0,
  	192,62,1,0,0,0,193,197,7,0,0,0,194,196,7,1,0,0,195,194,1,0,0,0,196,199,
  	1,0,0,0,197,195,1,0,0,0,197,198,1,0,0,0,198,64,1,0,0,0,199,197,1,0,0,
  	0,200,202,2,48,57,0,201,200,1,0,0,0,202,203,1,0,0,0,203,201,1,0,0,0,203,
  	204,1,0,0,0,204,66,1,0,0,0,205,206,5,116,0,0,206,207,5,114,0,0,207,208,
  	5,117,0,0,208,215,5,101,0,0,209,210,5,102,0,0,210,211,5,97,0,0,211,212,
  	5,108,0,0,212,213,5,115,0,0,213,215,5,101,0,0,214,205,1,0,0,0,214,209,
  	1,0,0,0,215,68,1,0,0,0,216,218,2,48,57,0,217,216,1,0,0,0,218,219,1,0,
  	0,0,219,217,1,0,0,0,219,220,1,0,0,0,220,221,1,0,0,0,221,223,5,46,0,0,
  	222,224,2,48,57,0,223,222,1,0,0,0,224,225,1,0,0,0,225,223,1,0,0,0,225,
  	226,1,0,0,0,226,70,1,0,0,0,227,230,5,39,0,0,228,231,3,75,37,0,229,231,
  	8,2,0,0,230,228,1,0,0,0,230,229,1,0,0,0,231,232,1,0,0,0,232,233,5,39,
  	0,0,233,72,1,0,0,0,234,239,5,34,0,0,235,238,3,75,37,0,236,238,8,3,0,0,
  	237,235,1,0,0,0,237,236,1,0,0,0,238,241,1,0,0,0,239,237,1,0,0,0,239,240,
  	1,0,0,0,240,242,1,0,0,0,241,239,1,0,0,0,242,243,5,34,0,0,243,74,1,0,0,
  	0,244,245,5,92,0,0,245,246,7,4,0,0,246,76,1,0,0,0,247,248,5,47,0,0,248,
  	249,5,47,0,0,249,253,1,0,0,0,250,252,8,5,0,0,251,250,1,0,0,0,252,255,
  	1,0,0,0,253,251,1,0,0,0,253,254,1,0,0,0,254,257,1,0,0,0,255,253,1,0,0,
  	0,256,258,5,13,0,0,257,256,1,0,0,0,257,258,1,0,0,0,258,259,1,0,0,0,259,
  	260,5,10,0,0,260,261,1,0,0,0,261,262,6,38,0,0,262,78,1,0,0,0,263,265,
  	7,6,0,0,264,263,1,0,0,0,265,266,1,0,0,0,266,264,1,0,0,0,266,267,1,0,0,
  	0,267,268,1,0,0,0,268,269,6,39,0,0,269,80,1,0,0,0,12,0,197,203,214,219,
  	225,230,237,239,253,257,266,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  asllexerLexerStaticData = std::move(staticData);
}

}

AslLexer::AslLexer(CharStream *input) : Lexer(input) {
  AslLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *asllexerLexerStaticData->atn, asllexerLexerStaticData->decisionToDFA, asllexerLexerStaticData->sharedContextCache);
}

AslLexer::~AslLexer() {
  delete _interpreter;
}

std::string AslLexer::getGrammarFileName() const {
  return "Asl.g4";
}

const std::vector<std::string>& AslLexer::getRuleNames() const {
  return asllexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& AslLexer::getChannelNames() const {
  return asllexerLexerStaticData->channelNames;
}

const std::vector<std::string>& AslLexer::getModeNames() const {
  return asllexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& AslLexer::getVocabulary() const {
  return asllexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView AslLexer::getSerializedATN() const {
  return asllexerLexerStaticData->serializedATN;
}

const atn::ATN& AslLexer::getATN() const {
  return *asllexerLexerStaticData->atn;
}




void AslLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  asllexerLexerInitialize();
#else
  ::antlr4::internal::call_once(asllexerLexerOnceFlag, asllexerLexerInitialize);
#endif
}
