#include <gtest/gtest.h>
#include "Polynom.h"


TEST(Polynom, EmptyCheck)
{
    Polynom p;
    EXPECT_TRUE(p.empty());
    EXPECT_EQ(p.size(), 0);
}


TEST(Polynom, AddOneMonom)
{
    Polynom p;
    p += Monom(3.0, 2, 0, 0);

    EXPECT_FALSE(p.empty());
    EXPECT_EQ(p.size(), 1);
}


TEST(Polynom, MergeEqualMonoms)
{
    Polynom p;
    p += Monom(2.0, 1, 0, 0);
    p += Monom(3.0, 1, 0, 0);

    EXPECT_EQ(p.size(), 1);

    TLink<Monom>* t = p.terms.fp;
    ASSERT_NE(t, nullptr);
    EXPECT_DOUBLE_EQ(t->val.getCoef(), 5.0);
}


TEST(Polynom, RemoveZeroAfterMerge)
{
    Polynom p;
    p += Monom(2.0, 1, 0, 0);
    p += Monom(-2.0, 1, 0, 0);

    EXPECT_TRUE(p.empty());
}


TEST(Polynom, AddPolynoms)
{
    Polynom a;
    a += Monom(2.0, 1, 0, 0);
    a += Monom(1.0, 0, 1, 0);

    Polynom b;
    b += Monom(3.0, 1, 0, 0);
    b += Monom(4.0, 0, 0, 1);

    a += b;

    EXPECT_EQ(a.size(), 3);
}


TEST(Polynom, SubtractPolynoms)
{
    Polynom a;
    a += Monom(5.0, 1, 0, 0);

    Polynom b;
    b += Monom(3.0, 1, 0, 0);

    a -= b;

    EXPECT_EQ(a.size(), 1);

    TLink<Monom>* t = a.terms.fp;
    ASSERT_NE(t, nullptr);
    EXPECT_DOUBLE_EQ(t->val.getCoef(), 2.0);
}


TEST(Polynom, MultiplyPolynoms)
{
    Polynom a;
    a += Monom(2.0, 1, 0, 0);   // 2x

    Polynom b;
    b += Monom(3.0, 0, 1, 0);   // 3y

    a *= b;  // 6xy

    EXPECT_EQ(a.size(), 1);

    TLink<Monom>* t = a.terms.fp;
    ASSERT_NE(t, nullptr);

    EXPECT_DOUBLE_EQ(t->val.getCoef(), 6.0);
    EXPECT_EQ(t->val.getI(), 1);
    EXPECT_EQ(t->val.getJ(), 1);
}


TEST(Polynom, ValueCalculation)
{
    Polynom p;
    p += Monom(2.0, 2, 0, 0);   // 2x^2
    p += Monom(1.0, 0, 1, 0);   // + y

    double val = p.value(3.0, 4.0, 0.0); 
    // 2*9 + 4 = 22

    EXPECT_DOUBLE_EQ(val, 22.0);
}


TEST(Polynom, MultiplyByZero)
{
    Polynom a;
    a += Monom(2.0, 1, 0, 0);

    Polynom b; // пустой

    a *= b;

    EXPECT_TRUE(a.empty());
}