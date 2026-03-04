
// Generated from parser/grammar/Polynom.g4 by ANTLR 4.13.2


#include "PolynomLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct PolynomLexerStaticData final {
  PolynomLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PolynomLexerStaticData(const PolynomLexerStaticData&) = delete;
  PolynomLexerStaticData(PolynomLexerStaticData&&) = delete;
  PolynomLexerStaticData& operator=(const PolynomLexerStaticData&) = delete;
  PolynomLexerStaticData& operator=(PolynomLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag polynomlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<PolynomLexerStaticData> polynomlexerLexerStaticData = nullptr;

void polynomlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (polynomlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(polynomlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<PolynomLexerStaticData>(
    std::vector<std::string>{
      "PLUS", "MINUS", "MUL", "POW", "LPAREN", "RPAREN", "NUMBER", "INT", 
      "VAR", "DIGIT", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'+'", "'-'", "'*'", "'^'", "'('", "')'"
    },
    std::vector<std::string>{
      "", "PLUS", "MINUS", "MUL", "POW", "LPAREN", "RPAREN", "NUMBER", "INT", 
      "VAR", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,10,67,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,
  	4,1,4,1,5,1,5,1,6,4,6,37,8,6,11,6,12,6,38,1,6,1,6,4,6,43,8,6,11,6,12,
  	6,44,3,6,47,8,6,1,7,3,7,50,8,7,1,7,4,7,53,8,7,11,7,12,7,54,1,8,1,8,1,
  	9,1,9,1,10,4,10,62,8,10,11,10,12,10,63,1,10,1,10,0,0,11,1,1,3,2,5,3,7,
  	4,9,5,11,6,13,7,15,8,17,9,19,0,21,10,1,0,4,2,0,43,43,45,45,1,0,120,122,
  	1,0,48,57,3,0,9,10,13,13,32,32,71,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,
  	0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,
  	0,0,0,0,21,1,0,0,0,1,23,1,0,0,0,3,25,1,0,0,0,5,27,1,0,0,0,7,29,1,0,0,
  	0,9,31,1,0,0,0,11,33,1,0,0,0,13,36,1,0,0,0,15,49,1,0,0,0,17,56,1,0,0,
  	0,19,58,1,0,0,0,21,61,1,0,0,0,23,24,5,43,0,0,24,2,1,0,0,0,25,26,5,45,
  	0,0,26,4,1,0,0,0,27,28,5,42,0,0,28,6,1,0,0,0,29,30,5,94,0,0,30,8,1,0,
  	0,0,31,32,5,40,0,0,32,10,1,0,0,0,33,34,5,41,0,0,34,12,1,0,0,0,35,37,3,
  	19,9,0,36,35,1,0,0,0,37,38,1,0,0,0,38,36,1,0,0,0,38,39,1,0,0,0,39,46,
  	1,0,0,0,40,42,5,46,0,0,41,43,3,19,9,0,42,41,1,0,0,0,43,44,1,0,0,0,44,
  	42,1,0,0,0,44,45,1,0,0,0,45,47,1,0,0,0,46,40,1,0,0,0,46,47,1,0,0,0,47,
  	14,1,0,0,0,48,50,7,0,0,0,49,48,1,0,0,0,49,50,1,0,0,0,50,52,1,0,0,0,51,
  	53,3,19,9,0,52,51,1,0,0,0,53,54,1,0,0,0,54,52,1,0,0,0,54,55,1,0,0,0,55,
  	16,1,0,0,0,56,57,7,1,0,0,57,18,1,0,0,0,58,59,7,2,0,0,59,20,1,0,0,0,60,
  	62,7,3,0,0,61,60,1,0,0,0,62,63,1,0,0,0,63,61,1,0,0,0,63,64,1,0,0,0,64,
  	65,1,0,0,0,65,66,6,10,0,0,66,22,1,0,0,0,7,0,38,44,46,49,54,63,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  polynomlexerLexerStaticData = std::move(staticData);
}

}

PolynomLexer::PolynomLexer(CharStream *input) : Lexer(input) {
  PolynomLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *polynomlexerLexerStaticData->atn, polynomlexerLexerStaticData->decisionToDFA, polynomlexerLexerStaticData->sharedContextCache);
}

PolynomLexer::~PolynomLexer() {
  delete _interpreter;
}

std::string PolynomLexer::getGrammarFileName() const {
  return "Polynom.g4";
}

const std::vector<std::string>& PolynomLexer::getRuleNames() const {
  return polynomlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& PolynomLexer::getChannelNames() const {
  return polynomlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& PolynomLexer::getModeNames() const {
  return polynomlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& PolynomLexer::getVocabulary() const {
  return polynomlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView PolynomLexer::getSerializedATN() const {
  return polynomlexerLexerStaticData->serializedATN;
}

const atn::ATN& PolynomLexer::getATN() const {
  return *polynomlexerLexerStaticData->atn;
}




void PolynomLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  polynomlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(polynomlexerLexerOnceFlag, polynomlexerLexerInitialize);
#endif
}
