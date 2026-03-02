#include <gtest/gtest.h>
#include "Monom.h"
#include "string"
TEST(MonomT, ZeroCheck) {
    Monom m;
    EXPECT_TRUE(m.isZero());
}