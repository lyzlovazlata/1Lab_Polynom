#include <gtest/gtest.h>
#include "Monom.h"

TEST(MonomTest, ZeroCheck) {
    Monom m;   // если у тебя по умолчанию 0
    EXPECT_TRUE(m.isZero());
}