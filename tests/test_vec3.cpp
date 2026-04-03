#include <gtest/gtest.h>
#include "vec3.h"

TEST(Vec3Test, DefaultConstructor) {
    vec3 v;
    EXPECT_DOUBLE_EQ(v.x(), 0.0);
    EXPECT_DOUBLE_EQ(v.y(), 0.0);
    EXPECT_DOUBLE_EQ(v.z(), 0.0);
}

TEST(Vec3Test, ValueConstructor) {
    vec3 v(1.0, 2.0, 3.0);
    EXPECT_DOUBLE_EQ(v.x(), 1.0);
    EXPECT_DOUBLE_EQ(v.y(), 2.0);
    EXPECT_DOUBLE_EQ(v.z(), 3.0);
}

TEST(Vec3Test, ArithmeticOperations) {
    vec3 v1(1.0, 2.0, 3.0);
    vec3 v2(4.0, 5.0, 6.0);
    
    vec3 add = v1 + v2;
    EXPECT_DOUBLE_EQ(add.x(), 5.0);
    EXPECT_DOUBLE_EQ(add.y(), 7.0);
    EXPECT_DOUBLE_EQ(add.z(), 9.0);

    vec3 mul = v1 * 2.0;
    EXPECT_DOUBLE_EQ(mul.x(), 2.0);
    EXPECT_DOUBLE_EQ(mul.y(), 4.0);
    EXPECT_DOUBLE_EQ(mul.z(), 6.0);
}

TEST(Vec3Test, LengthAndDot) {
    vec3 v(0.0, 3.0, 4.0);
    EXPECT_DOUBLE_EQ(v.length_squared(), 25.0);
    EXPECT_DOUBLE_EQ(v.length(), 5.0);

    vec3 v1(1.0, 0.0, 0.0);
    vec3 v2(0.0, 1.0, 0.0);
    EXPECT_DOUBLE_EQ(dot(v1, v2), 0.0); // 直交
}

TEST(Vec3Test, CrossProduct) {
    vec3 x(1.0, 0.0, 0.0);
    vec3 y(0.0, 1.0, 0.0);
    vec3 z = cross(x, y);
    EXPECT_DOUBLE_EQ(z.x(), 0.0);
    EXPECT_DOUBLE_EQ(z.y(), 0.0);
    EXPECT_DOUBLE_EQ(z.z(), 1.0);
}