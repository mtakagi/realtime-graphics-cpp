#include <gtest/gtest.h>

#include "vec2.h"

TEST(Vec2Test, BasicOperations) {
    vec2 v(3.0, 4.0);
    EXPECT_DOUBLE_EQ(v.x(), 3.0);
    EXPECT_DOUBLE_EQ(v.y(), 4.0);
    EXPECT_DOUBLE_EQ(v.length(), 5.0);

    vec2 unit = unit_vector(v);
    EXPECT_DOUBLE_EQ(unit.length(), 1.0);
    EXPECT_DOUBLE_EQ(unit.x(), 3.0 / 5.0);
}