#include <gtest/gtest.h>

#include "mymath.h"

TEST(MyMathTest, Lerp) {
    EXPECT_DOUBLE_EQ(lerp(0.0, 10.0, 0.5), 5.0);
    EXPECT_DOUBLE_EQ(lerp(0.0, 10.0, 0.0), 0.0);
    EXPECT_DOUBLE_EQ(lerp(0.0, 10.0, 1.0), 10.0);
}

TEST(MyMathTest, Saturate) {
    EXPECT_DOUBLE_EQ(saturate(0.5), 0.5);
    EXPECT_DOUBLE_EQ(saturate(-1.0), 0.0);
    EXPECT_DOUBLE_EQ(saturate(2.0), 1.0);
}

TEST(MyMathTest, Frac) {
    EXPECT_DOUBLE_EQ(frac(1.25), 0.25);
    EXPECT_DOUBLE_EQ(frac(3.0), 0.0);
    // 負の数の frac の挙動 (GLSLの fract(x) = x - floor(x) と同じか確認)
    EXPECT_DOUBLE_EQ(frac(-1.25), 0.75);
}

TEST(MyMathTest, ClampVec3) {
    vec3 v(0.5, -1.0, 2.0);
    vec3 min_val(0.0, 0.0, 0.0);
    vec3 max_val(1.0, 1.0, 1.0);

    vec3 res = clamp(v, min_val, max_val);
    EXPECT_DOUBLE_EQ(res.x(), 0.5);
    EXPECT_DOUBLE_EQ(res.y(), 0.0);
    EXPECT_DOUBLE_EQ(res.z(), 1.0);
}