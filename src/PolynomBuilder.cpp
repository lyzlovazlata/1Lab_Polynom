#include "PolynomBuilder.h"
#include <string>
#include <any>
#include <tuple>

// -------------------- polynom --------------------

std::any PolynomBuilder::visitPolynom(PolynomParser::PolynomContext *ctx)
{
    return visit(ctx->expr());
}

// -------------------- expr (+ -) --------------------

std::any PolynomBuilder::visitExpr(PolynomParser::ExprContext *ctx)
{
    Polynom result = std::any_cast<Polynom>(visit(ctx->term(0)));

    for (size_t i = 1; i < ctx->term().size(); ++i)
    {
        Polynom rhs = std::any_cast<Polynom>(visit(ctx->term(i)));

        if (ctx->MINUS(i - 1))
            result -= rhs;
        else
            result += rhs;
    }

    return result;
}

// -------------------- term (*) --------------------

std::any PolynomBuilder::visitTerm(PolynomParser::TermContext *ctx)
{
    Polynom result = std::any_cast<Polynom>(visit(ctx->factor(0)));

    for (size_t i = 1; i < ctx->factor().size(); ++i)
    {
        Polynom rhs = std::any_cast<Polynom>(visit(ctx->factor(i)));
        result *= rhs;
    }

    return result;
}

// -------------------- factor --------------------

std::any PolynomBuilder::visitFactor(PolynomParser::FactorContext *ctx)
{
    bool negative = ctx->MINUS() != nullptr;

    if (ctx->expr())
    {
        Polynom p = std::any_cast<Polynom>(visit(ctx->expr()));

        if (negative)
            for (auto t = p.terms.fp; t; t = t->next) {
                t->val *= -1.0;
            }  // лучше чем лазить руками по списку

        return p;
    }

    double coef = 1.0;

    if (ctx->NUMBER())
        coef = std::stod(ctx->NUMBER()->getText());

    if (negative)
        coef *= -1.0;

    int i = 0, j = 0, k = 0;

    if (ctx->variableSeq())
    {
        auto powers = std::any_cast<std::tuple<int,int,int>>(
            visit(ctx->variableSeq())
        );

        i = std::get<0>(powers);
        j = std::get<1>(powers);
        k = std::get<2>(powers);
    }

    Polynom p;
    p.addMonomSorted(Monom(coef, i, j, k));

    return p;
}

// -------------------- variableSeq --------------------

std::any PolynomBuilder::visitVariableSeq(PolynomParser::VariableSeqContext *ctx)
{
    int i = 0, j = 0, k = 0;

    for (auto v : ctx->variablePow())
    {
        auto one = std::any_cast<std::tuple<int,int,int>>(visit(v));

        i += std::get<0>(one);
        j += std::get<1>(one);
        k += std::get<2>(one);
    }

    return std::make_tuple(i, j, k);
}

// -------------------- variablePow --------------------

std::any PolynomBuilder::visitVariablePow(PolynomParser::VariablePowContext *ctx)
{
    std::string var = ctx->VAR()->getText();

    int power = 1;

    if (ctx->INT())
        power = std::stoi(ctx->INT()->getText());

    int i = 0, j = 0, k = 0;

    if (var == "x") i = power;
    else if (var == "y") j = power;
    else if (var == "z") k = power;

    return std::make_tuple(i, j, k);
}