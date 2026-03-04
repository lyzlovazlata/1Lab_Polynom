
// Generated from parser/grammar/Polynom.g4 by ANTLR 4.13.2


#include "PolynomVisitor.h"

#include "PolynomParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct PolynomParserStaticData final {
  PolynomParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PolynomParserStaticData(const PolynomParserStaticData&) = delete;
  PolynomParserStaticData(PolynomParserStaticData&&) = delete;
  PolynomParserStaticData& operator=(const PolynomParserStaticData&) = delete;
  PolynomParserStaticData& operator=(PolynomParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag polynomParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<PolynomParserStaticData> polynomParserStaticData = nullptr;

void polynomParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (polynomParserStaticData != nullptr) {
    return;
  }
#else
  assert(polynomParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<PolynomParserStaticData>(
    std::vector<std::string>{
      "polynom", "expr", "term", "factor", "variableSeq", "variablePow"
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
  	4,1,10,58,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,1,0,1,0,1,0,
  	1,1,1,1,1,1,5,1,19,8,1,10,1,12,1,22,9,1,1,2,1,2,3,2,26,8,2,1,2,5,2,29,
  	8,2,10,2,12,2,32,9,2,1,3,3,3,35,8,3,1,3,1,3,3,3,39,8,3,1,3,1,3,1,3,1,
  	3,1,3,3,3,46,8,3,1,4,4,4,49,8,4,11,4,12,4,50,1,5,1,5,1,5,3,5,56,8,5,1,
  	5,0,0,6,0,2,4,6,8,10,0,1,1,0,1,2,60,0,12,1,0,0,0,2,15,1,0,0,0,4,23,1,
  	0,0,0,6,34,1,0,0,0,8,48,1,0,0,0,10,52,1,0,0,0,12,13,3,2,1,0,13,14,5,0,
  	0,1,14,1,1,0,0,0,15,20,3,4,2,0,16,17,7,0,0,0,17,19,3,4,2,0,18,16,1,0,
  	0,0,19,22,1,0,0,0,20,18,1,0,0,0,20,21,1,0,0,0,21,3,1,0,0,0,22,20,1,0,
  	0,0,23,30,3,6,3,0,24,26,5,3,0,0,25,24,1,0,0,0,25,26,1,0,0,0,26,27,1,0,
  	0,0,27,29,3,6,3,0,28,25,1,0,0,0,29,32,1,0,0,0,30,28,1,0,0,0,30,31,1,0,
  	0,0,31,5,1,0,0,0,32,30,1,0,0,0,33,35,7,0,0,0,34,33,1,0,0,0,34,35,1,0,
  	0,0,35,45,1,0,0,0,36,38,5,7,0,0,37,39,3,8,4,0,38,37,1,0,0,0,38,39,1,0,
  	0,0,39,46,1,0,0,0,40,46,3,8,4,0,41,42,5,5,0,0,42,43,3,2,1,0,43,44,5,6,
  	0,0,44,46,1,0,0,0,45,36,1,0,0,0,45,40,1,0,0,0,45,41,1,0,0,0,46,7,1,0,
  	0,0,47,49,3,10,5,0,48,47,1,0,0,0,49,50,1,0,0,0,50,48,1,0,0,0,50,51,1,
  	0,0,0,51,9,1,0,0,0,52,55,5,9,0,0,53,54,5,4,0,0,54,56,5,8,0,0,55,53,1,
  	0,0,0,55,56,1,0,0,0,56,11,1,0,0,0,8,20,25,30,34,38,45,50,55
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  polynomParserStaticData = std::move(staticData);
}

}

PolynomParser::PolynomParser(TokenStream *input) : PolynomParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

PolynomParser::PolynomParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  PolynomParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *polynomParserStaticData->atn, polynomParserStaticData->decisionToDFA, polynomParserStaticData->sharedContextCache, options);
}

PolynomParser::~PolynomParser() {
  delete _interpreter;
}

const atn::ATN& PolynomParser::getATN() const {
  return *polynomParserStaticData->atn;
}

std::string PolynomParser::getGrammarFileName() const {
  return "Polynom.g4";
}

const std::vector<std::string>& PolynomParser::getRuleNames() const {
  return polynomParserStaticData->ruleNames;
}

const dfa::Vocabulary& PolynomParser::getVocabulary() const {
  return polynomParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView PolynomParser::getSerializedATN() const {
  return polynomParserStaticData->serializedATN;
}


//----------------- PolynomContext ------------------------------------------------------------------

PolynomParser::PolynomContext::PolynomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PolynomParser::ExprContext* PolynomParser::PolynomContext::expr() {
  return getRuleContext<PolynomParser::ExprContext>(0);
}

tree::TerminalNode* PolynomParser::PolynomContext::EOF() {
  return getToken(PolynomParser::EOF, 0);
}


size_t PolynomParser::PolynomContext::getRuleIndex() const {
  return PolynomParser::RulePolynom;
}


std::any PolynomParser::PolynomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PolynomVisitor*>(visitor))
    return parserVisitor->visitPolynom(this);
  else
    return visitor->visitChildren(this);
}

PolynomParser::PolynomContext* PolynomParser::polynom() {
  PolynomContext *_localctx = _tracker.createInstance<PolynomContext>(_ctx, getState());
  enterRule(_localctx, 0, PolynomParser::RulePolynom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(12);
    expr();
    setState(13);
    match(PolynomParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

PolynomParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PolynomParser::TermContext *> PolynomParser::ExprContext::term() {
  return getRuleContexts<PolynomParser::TermContext>();
}

PolynomParser::TermContext* PolynomParser::ExprContext::term(size_t i) {
  return getRuleContext<PolynomParser::TermContext>(i);
}

std::vector<tree::TerminalNode *> PolynomParser::ExprContext::PLUS() {
  return getTokens(PolynomParser::PLUS);
}

tree::TerminalNode* PolynomParser::ExprContext::PLUS(size_t i) {
  return getToken(PolynomParser::PLUS, i);
}

std::vector<tree::TerminalNode *> PolynomParser::ExprContext::MINUS() {
  return getTokens(PolynomParser::MINUS);
}

tree::TerminalNode* PolynomParser::ExprContext::MINUS(size_t i) {
  return getToken(PolynomParser::MINUS, i);
}


size_t PolynomParser::ExprContext::getRuleIndex() const {
  return PolynomParser::RuleExpr;
}


std::any PolynomParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PolynomVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

PolynomParser::ExprContext* PolynomParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 2, PolynomParser::RuleExpr);
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
    setState(15);
    term();
    setState(20);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PolynomParser::PLUS

    || _la == PolynomParser::MINUS) {
      setState(16);
      _la = _input->LA(1);
      if (!(_la == PolynomParser::PLUS

      || _la == PolynomParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(17);
      term();
      setState(22);
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

//----------------- TermContext ------------------------------------------------------------------

PolynomParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PolynomParser::FactorContext *> PolynomParser::TermContext::factor() {
  return getRuleContexts<PolynomParser::FactorContext>();
}

PolynomParser::FactorContext* PolynomParser::TermContext::factor(size_t i) {
  return getRuleContext<PolynomParser::FactorContext>(i);
}

std::vector<tree::TerminalNode *> PolynomParser::TermContext::MUL() {
  return getTokens(PolynomParser::MUL);
}

tree::TerminalNode* PolynomParser::TermContext::MUL(size_t i) {
  return getToken(PolynomParser::MUL, i);
}


size_t PolynomParser::TermContext::getRuleIndex() const {
  return PolynomParser::RuleTerm;
}


std::any PolynomParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PolynomVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

PolynomParser::TermContext* PolynomParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 4, PolynomParser::RuleTerm);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(23);
    factor();
    setState(30);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(25);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PolynomParser::MUL) {
          setState(24);
          match(PolynomParser::MUL);
        }
        setState(27);
        factor(); 
      }
      setState(32);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

PolynomParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PolynomParser::FactorContext::NUMBER() {
  return getToken(PolynomParser::NUMBER, 0);
}

PolynomParser::VariableSeqContext* PolynomParser::FactorContext::variableSeq() {
  return getRuleContext<PolynomParser::VariableSeqContext>(0);
}

tree::TerminalNode* PolynomParser::FactorContext::LPAREN() {
  return getToken(PolynomParser::LPAREN, 0);
}

PolynomParser::ExprContext* PolynomParser::FactorContext::expr() {
  return getRuleContext<PolynomParser::ExprContext>(0);
}

tree::TerminalNode* PolynomParser::FactorContext::RPAREN() {
  return getToken(PolynomParser::RPAREN, 0);
}

tree::TerminalNode* PolynomParser::FactorContext::PLUS() {
  return getToken(PolynomParser::PLUS, 0);
}

tree::TerminalNode* PolynomParser::FactorContext::MINUS() {
  return getToken(PolynomParser::MINUS, 0);
}


size_t PolynomParser::FactorContext::getRuleIndex() const {
  return PolynomParser::RuleFactor;
}


std::any PolynomParser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PolynomVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

PolynomParser::FactorContext* PolynomParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 6, PolynomParser::RuleFactor);
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
    setState(34);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PolynomParser::PLUS

    || _la == PolynomParser::MINUS) {
      setState(33);
      _la = _input->LA(1);
      if (!(_la == PolynomParser::PLUS

      || _la == PolynomParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(45);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PolynomParser::NUMBER: {
        setState(36);
        match(PolynomParser::NUMBER);
        setState(38);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          setState(37);
          variableSeq();
          break;
        }

        default:
          break;
        }
        break;
      }

      case PolynomParser::VAR: {
        setState(40);
        variableSeq();
        break;
      }

      case PolynomParser::LPAREN: {
        setState(41);
        match(PolynomParser::LPAREN);
        setState(42);
        expr();
        setState(43);
        match(PolynomParser::RPAREN);
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

//----------------- VariableSeqContext ------------------------------------------------------------------

PolynomParser::VariableSeqContext::VariableSeqContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PolynomParser::VariablePowContext *> PolynomParser::VariableSeqContext::variablePow() {
  return getRuleContexts<PolynomParser::VariablePowContext>();
}

PolynomParser::VariablePowContext* PolynomParser::VariableSeqContext::variablePow(size_t i) {
  return getRuleContext<PolynomParser::VariablePowContext>(i);
}


size_t PolynomParser::VariableSeqContext::getRuleIndex() const {
  return PolynomParser::RuleVariableSeq;
}


std::any PolynomParser::VariableSeqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PolynomVisitor*>(visitor))
    return parserVisitor->visitVariableSeq(this);
  else
    return visitor->visitChildren(this);
}

PolynomParser::VariableSeqContext* PolynomParser::variableSeq() {
  VariableSeqContext *_localctx = _tracker.createInstance<VariableSeqContext>(_ctx, getState());
  enterRule(_localctx, 8, PolynomParser::RuleVariableSeq);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(48); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(47);
              variablePow();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(50); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariablePowContext ------------------------------------------------------------------

PolynomParser::VariablePowContext::VariablePowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PolynomParser::VariablePowContext::VAR() {
  return getToken(PolynomParser::VAR, 0);
}

tree::TerminalNode* PolynomParser::VariablePowContext::POW() {
  return getToken(PolynomParser::POW, 0);
}

tree::TerminalNode* PolynomParser::VariablePowContext::INT() {
  return getToken(PolynomParser::INT, 0);
}


size_t PolynomParser::VariablePowContext::getRuleIndex() const {
  return PolynomParser::RuleVariablePow;
}


std::any PolynomParser::VariablePowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PolynomVisitor*>(visitor))
    return parserVisitor->visitVariablePow(this);
  else
    return visitor->visitChildren(this);
}

PolynomParser::VariablePowContext* PolynomParser::variablePow() {
  VariablePowContext *_localctx = _tracker.createInstance<VariablePowContext>(_ctx, getState());
  enterRule(_localctx, 10, PolynomParser::RuleVariablePow);
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
    setState(52);
    match(PolynomParser::VAR);
    setState(55);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PolynomParser::POW) {
      setState(53);
      match(PolynomParser::POW);
      setState(54);
      match(PolynomParser::INT);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void PolynomParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  polynomParserInitialize();
#else
  ::antlr4::internal::call_once(polynomParserOnceFlag, polynomParserInitialize);
#endif
}
