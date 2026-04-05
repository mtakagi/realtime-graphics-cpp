//
// Created by mtakagi on 2026/04/06.
//

#include <gtest/gtest.h>

#include "uvec2.h"

// 1. コンストラクタのテスト
TEST(UVec2Test, Constructors) {
    // デフォルトコンストラクタ
    uvec2 v1;
    EXPECT_EQ(v1.x(), 0u);
    EXPECT_EQ(v1.y(), 0u);

    // 単一値コンストラクタ
    uvec2 v2(5u);
    EXPECT_EQ(v2.x(), 5u);
    EXPECT_EQ(v2.y(), 5u);

    // 2値コンストラクタ
    uvec2 v3(3u, 4u);
    EXPECT_EQ(v3.x(), 3u);
    EXPECT_EQ(v3.y(), 4u);
}

// 2. ゲッター・セッターのテスト
TEST(UVec2Test, GettersAndSetters) {
    uvec2 v;
    v.setX(10u);
    v.setY(20u);

    EXPECT_EQ(v.x(), 10u);
    EXPECT_EQ(v.y(), 20u);
}

// 3. 添字演算子 (operator[]) のテスト
TEST(UVec2Test, SubscriptOperator) {
    uvec2 v(7u, 8u);

    // const読み取り
    EXPECT_EQ(v[0], 7u);
    EXPECT_EQ(v[1], 8u);

    // 参照による書き込み
    v[0] = 10u;
    v[1] = 20u;
    EXPECT_EQ(v.x(), 10u);
    EXPECT_EQ(v.y(), 20u);
}

// 5. 複合代入演算子のテスト (+=, *=, /=)
TEST(UVec2Test, CompoundAssignments) {
    uvec2 v(2u, 3u);

    // += (uvec2)
    v += uvec2(3u, 4u);
    EXPECT_EQ(v.x(), 5u);
    EXPECT_EQ(v.y(), 7u);

    // *= (uint32_t)
    v *= 2u;
    EXPECT_EQ(v.x(), 10u);
    EXPECT_EQ(v.y(), 14u);

    // *= (uvec2)
    v *= uvec2(2u, 3u);
    EXPECT_EQ(v.x(), 20u);
    EXPECT_EQ(v.y(), 42u);

    // /= (uint32_t)
    v /= 2u;
    EXPECT_EQ(v.x(), 10u);
    EXPECT_EQ(v.y(), 21u);
}

// 6. 二項演算子のテスト (+, -, *, /)
TEST(UVec2Test, BinaryArithmetic) {
    uvec2 v1(10u, 20u);
    uvec2 v2(2u, 4u);

    // +
    uvec2 add1 = v1 + v2;
    EXPECT_EQ(add1.x(), 12u);
    EXPECT_EQ(add1.y(), 24u);

    uvec2 add2 = v1 + 5u;
    EXPECT_EQ(add2.x(), 15u);
    EXPECT_EQ(add2.y(), 25u);

    // -
    uvec2 sub1 = v1 - v2;
    EXPECT_EQ(sub1.x(), 8u);
    EXPECT_EQ(sub1.y(), 16u);

    uvec2 sub2 = v1 - 5u;
    EXPECT_EQ(sub2.x(), 5u);
    EXPECT_EQ(sub2.y(), 15u);

    uvec2 sub3 = 30u - v1;
    EXPECT_EQ(sub3.x(), 20u);
    EXPECT_EQ(sub3.y(), 10u);

    // *
    uvec2 mul1 = v1 * v2;
    EXPECT_EQ(mul1.x(), 20u);
    EXPECT_EQ(mul1.y(), 80u);

    uvec2 mul2 = v1 * 2u;
    EXPECT_EQ(mul2.x(), 20u);
    EXPECT_EQ(mul2.y(), 40u);

    uvec2 mul3 = 3u * v1;
    EXPECT_EQ(mul3.x(), 30u);
    EXPECT_EQ(mul3.y(), 60u);

    // /
    uvec2 div1 = v1 / v2;
    EXPECT_EQ(div1.x(), 5u);
    EXPECT_EQ(div1.y(), 5u);

    uvec2 div2 = v1 / 2u;
    EXPECT_EQ(div2.x(), 5u);
    EXPECT_EQ(div2.y(), 10u);
}

// 7. 比較演算子のテスト (<, <=, >, >=)
TEST(UVec2Test, Comparisons) {
    uvec2 v1(5u, 10u);
    uvec2 v2(10u, 10u);

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

// 8. ベクトル演算のテスト (length, dot, unit_vector)
TEST(UVec2Test, VectorOperations) {
    uvec2 v(3u, 4u);

    // 内積
    uvec2 u(2u, 5u);
    EXPECT_EQ(dot(v, u), 6u + 20u);  // 26

    // 長さと長さの2乗
    EXPECT_EQ(v.length_squared(), 25u);
    EXPECT_EQ(v.length(), 5u);  // sqrt(25) = 5
}