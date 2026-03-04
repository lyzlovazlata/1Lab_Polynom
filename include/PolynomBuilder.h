#pragma once

#include "PolynomBaseVisitor.h"
#include "Polynom.h"
#include "Monom.h"

class PolynomBuilder : public PolynomBaseVisitor
{
public:
    antlrcpp::Any visitPolynom(PolynomParser::PolynomContext *ctx) override;
    antlrcpp::Any visitExpr(PolynomParser::ExprContext *ctx) override;
    antlrcpp::Any visitTerm(PolynomParser::TermContext *ctx) override;
    antlrcpp::Any visitFactor(PolynomParser::FactorContext *ctx) override;
    antlrcpp::Any visitVariableSeq(PolynomParser::VariableSeqContext *ctx) override;
    antlrcpp::Any visitVariablePow(PolynomParser::VariablePowContext *ctx) override;
};