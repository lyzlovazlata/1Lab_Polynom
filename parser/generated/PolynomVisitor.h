
// Generated from parser/grammar/Polynom.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "PolynomParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by PolynomParser.
 */
class  PolynomVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by PolynomParser.
   */
    virtual std::any visitPolynom(PolynomParser::PolynomContext *context) = 0;

    virtual std::any visitExpr(PolynomParser::ExprContext *context) = 0;

    virtual std::any visitTerm(PolynomParser::TermContext *context) = 0;

    virtual std::any visitFactor(PolynomParser::FactorContext *context) = 0;

    virtual std::any visitVariableSeq(PolynomParser::VariableSeqContext *context) = 0;

    virtual std::any visitVariablePow(PolynomParser::VariablePowContext *context) = 0;


};

