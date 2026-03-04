#include <gtest/gtest.h>
#include "Monom.h"


TEST(Monom, DefaultIsZero)
{
    Monom m;
    EXPECT_TRUE(m.isZero());
    EXPECT_EQ(m.getI(), 0);
    EXPECT_EQ(m.getJ(), 0);
    EXPECT_EQ(m.getK(), 0);
}

TEST(Monom, ConstructorAndGetters)
{
    Monom m(3.5, 2, -1, 0);

    EXPECT_DOUBLE_EQ(m.getCoef(), 3.5);
    EXPECT_EQ(m.getI(), 2);
    EXPECT_EQ(m.getJ(), -1);
    EXPECT_EQ(m.getK(), 0);
}


TEST(Monom, EqualityByPowers)
{
    Monom a(2.0, 1, 2, 3);
    Monom b(5.0, 1, 2, 3);   // коэффициенты разные
    Monom c(2.0, 0, 2, 3);

    EXPECT_TRUE(a == b);   // сравнение только по степеням
    EXPECT_FALSE(a == c);
}


TEST(Monom, AdditionSamePowers)
{
    Monom a(2.0, 1, 0, 0);
    Monom b(3.0, 1, 0, 0);

    Monom result = a + b;

    EXPECT_DOUBLE_EQ(result.getCoef(), 5.0);
    EXPECT_EQ(result.getI(), 1);
}

TEST(Monom, AdditionToZero)
{
    Monom a(2.0, 1, 0, 0);
    Monom b(-2.0, 1, 0, 0);

    a += b;

    EXPECT_TRUE(a.isZero());
}


TEST(Monom, MultiplyMonoms)
{
    Monom a(2.0, 1, 2, 0);
    Monom b(3.0, -1, 1, 4);

    Monom result = a * b;

    EXPECT_DOUBLE_EQ(result.getCoef(), 6.0);
    EXPECT_EQ(result.getI(), 0);   // 1 + (-1)
    EXPECT_EQ(result.getJ(), 3);   // 2 + 1
    EXPECT_EQ(result.getK(), 4);   // 0 + 4
}


TEST(Monom, MultiplyByScalar)
{
    Monom a(2.0, 1, 0, 0);

    Monom result = a * 3.0;

    EXPECT_DOUBLE_EQ(result.getCoef(), 6.0);
    EXPECT_EQ(result.getI(), 1);
}

TEST(Monom, UnarMinus)
{
    Monom a(4.0, 2, 0, 0);

    Monom b = -a;

    EXPECT_DOUBLE_EQ(b.getCoef(), -4.0);
    EXPECT_EQ(b.getI(), 2);
}


TEST(Monom, ValueCalculation)
{
    Monom m(2.0, 2, 1, 0);   // 2 * x^2 * y

    double val = m.value(3.0, 2.0, 0.0);  // 2 * 9 * 2 = 36

    EXPECT_DOUBLE_EQ(val, 36.0);
}