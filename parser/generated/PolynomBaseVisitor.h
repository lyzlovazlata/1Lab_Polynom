
// Generated from parser/grammar/Polynom.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "PolynomVisitor.h"


/**
 * This class provides an empty implementation of PolynomVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  PolynomBaseVisitor : public PolynomVisitor {
public:

  virtual std::any visitPolynom(PolynomParser::PolynomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(PolynomParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTerm(PolynomParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor(PolynomParser::FactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableSeq(PolynomParser::VariableSeqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariablePow(PolynomParser::VariablePowContext *ctx) override {
    return visitChildren(ctx);
  }


};

