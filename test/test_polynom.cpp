#include <gtest/gtest.h>
#include "Polynom.h"

TEST(PolynomTest, EmptyCheck) {
    Polynom p;
    EXPECT_TRUE(p.empty());
}