//
// Created by mtakagi on 2026/04/06.
//

#include <gtest/gtest.h>

#include "ivec2.h"

// 1. コンストラクタのテスト
TEST(IVec2Test, Constructors) {
    // デフォルトコンストラクタ
    ivec2 v1;
    EXPECT_EQ(v1.x(), 0);
    EXPECT_EQ(v1.y(), 0);

    // 単一値コンストラクタ
    ivec2 v2(-5);
    EXPECT_EQ(v2.x(), -5);
    EXPECT_EQ(v2.y(), -5);

    // 2値コンストラクタ
    ivec2 v3(3, -4);
    EXPECT_EQ(v3.x(), 3);
    EXPECT_EQ(v3.y(), -4);
}

// 2. ゲッター・セッターのテスト
TEST(IVec2Test, GettersAndSetters) {
    ivec2 v;
    v.setX(-10);
    v.setY(20);

    EXPECT_EQ(v.x(), -10);
    EXPECT_EQ(v.y(), 20);
}

// 3. 添字演算子 (operator[]) のテスト
TEST(IVec2Test, SubscriptOperator) {
    ivec2 v(7, -8);

    // const読み取り
    EXPECT_EQ(v[0], 7);
    EXPECT_EQ(v[1], -8);

    // 参照による書き込み
    v[0] = -10;
    v[1] = 20;
    EXPECT_EQ(v.x(), -10);
    EXPECT_EQ(v.y(), 20);
}

// 4. 複合代入演算子のテスト (+=, *=, /=)
TEST(IVec2Test, CompoundAssignments) {
    ivec2 v(2, -3);

    // += (ivec2)
    v += ivec2(3, 4);
    EXPECT_EQ(v.x(), 5);
    EXPECT_EQ(v.y(), 1);

    // *= (int32_t)
    v *= -2;
    EXPECT_EQ(v.x(), -10);
    EXPECT_EQ(v.y(), -2);

    // *= (ivec2)
    v *= ivec2(2, -3);
    EXPECT_EQ(v.x(), -20);
    EXPECT_EQ(v.y(), 6);

    // /= (int32_t)
    v /= 2;
    EXPECT_EQ(v.x(), -10);
    EXPECT_EQ(v.y(), 3);
}

// 5. 二項演算子のテスト (+, -, *, /)
TEST(IVec2Test, BinaryArithmetic) {
    ivec2 v1(10, -20);
    ivec2 v2(-2, 4);

    // +
    ivec2 add1 = v1 + v2;
    EXPECT_EQ(add1.x(), 8);
    EXPECT_EQ(add1.y(), -16);

    ivec2 add2 = v1 + 5;
    EXPECT_EQ(add2.x(), 15);
    EXPECT_EQ(add2.y(), -15);

    // -
    ivec2 sub1 = v1 - v2;
    EXPECT_EQ(sub1.x(), 12);
    EXPECT_EQ(sub1.y(), -24);

    ivec2 sub2 = v1 - 5;
    EXPECT_EQ(sub2.x(), 5);
    EXPECT_EQ(sub2.y(), -25);

    ivec2 sub3 = 30 - v1;
    EXPECT_EQ(sub3.x(), 20);
    EXPECT_EQ(sub3.y(), 50);

    // *
    ivec2 mul1 = v1 * v2;
    EXPECT_EQ(mul1.x(), -20);
    EXPECT_EQ(mul1.y(), -80);

    ivec2 mul2 = v1 * -2;
    EXPECT_EQ(mul2.x(), -20);
    EXPECT_EQ(mul2.y(), 40);

    ivec2 mul3 = -3 * v1;
    EXPECT_EQ(mul3.x(), -30);
    EXPECT_EQ(mul3.y(), 60);

    // /
    ivec2 div1 = v1 / v2;
    EXPECT_EQ(div1.x(), -5);
    EXPECT_EQ(div1.y(), -5);

    ivec2 div2 = v1 / -2;
    EXPECT_EQ(div2.x(), -5);
    EXPECT_EQ(div2.y(), 10);
}

// 6. 比較演算子のテスト (<, <=, >, >=)
TEST(IVec2Test, Comparisons) {
    ivec2 v1(-5, 10);
    ivec2 v2(10, 10);

    bool2 less = v1 < v2;
    EXPECT_TRUE(less.x());
    EXPECT_FALSE(less.y());

    bool2 less_eq = v1 <= v2;
    EXPECT_TRUE(less_eq.x());
    EXPECT_TRUE(less_eq.y());

    bool2 greater = v2 > v1;
    EXPECT_TRUE(greater.x());
    EXPECT_FALSE(greater.y());

    bool2 greater_eq = v2 >= v1;
    EXPECT_TRUE(greater_eq.x());
    EXPECT_TRUE(greater_eq.y());
}

// 7. ベクトル演算のテスト (length, dot)
TEST(IVec2Test, VectorOperations) {
    ivec2 v(3, -4);

    // 内積
    ivec2 u(-2, 5);
    EXPECT_EQ(dot(v, u), -6 + -20);  // -26

    // 長さと長さの2乗
    EXPECT_EQ(v.length_squared(), 25);
    EXPECT_DOUBLE_EQ(v.length(), 5.0);  // sqrt(25) = 5.0
}