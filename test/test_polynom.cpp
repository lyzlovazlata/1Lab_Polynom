#include <gtest.h>
#include "Polynom.h"

TEST(Polynom, EmptyCheck) {
    Polynom p;
    EXPECT_TRUE(p.empty());
}