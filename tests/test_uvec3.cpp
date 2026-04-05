//
// Created by mtakagi on 2026/04/06.
//

#include <gtest/gtest.h>

#include "uvec3.h"

// 1. コンストラクタとゲッターのテスト
TEST(UVec3Test, ConstructorsAndGetters) {
    // デフォルトコンストラクタ
    uvec3 v1;
    EXPECT_EQ(v1.x(), 0u);
    EXPECT_EQ(v1.y(), 0u);
    EXPECT_EQ(v1.z(), 0u);

    // 単一値コンストラクタ
    uvec3 v2(5u);
    EXPECT_EQ(v2.x(), 5u);
    EXPECT_EQ(v2.y(), 5u);
    EXPECT_EQ(v2.z(), 5u);

    // 3値コンストラクタ
    uvec3 v3(3u, 4u, 5u);
    EXPECT_EQ(v3.x(), 3u);
    EXPECT_EQ(v3.y(), 4u);
    EXPECT_EQ(v3.z(), 5u);
}

// 2. 添字演算子 (operator[]) のテスト
TEST(UVec3Test, SubscriptOperator) {
    uvec3 v(7u, 8u, 9u);

    // const読み取り
    EXPECT_EQ(v[0], 7u);
    EXPECT_EQ(v[1], 8u);
    EXPECT_EQ(v[2], 9u);

    // 参照による書き込み
    v[0] = 10u;
    v[1] = 20u;
    v[2] = 30u;
    EXPECT_EQ(v.x(), 10u);
    EXPECT_EQ(v.y(), 20u);
    EXPECT_EQ(v.z(), 30u);
}

// 4. 複合代入演算子のテスト (+=, *=, /=)
TEST(UVec3Test, CompoundAssignments) {
    uvec3 v(2u, 3u, 4u);

    // += (uvec3)
    v += uvec3(3u, 4u, 5u);
    EXPECT_EQ(v.x(), 5u);
    EXPECT_EQ(v.y(), 7u);
    EXPECT_EQ(v.z(), 9u);

    // *= (uint32_t)
    v *= 2u;
    EXPECT_EQ(v.x(), 10u);
    EXPECT_EQ(v.y(), 14u);
    EXPECT_EQ(v.z(), 18u);

    // *= (uvec3)
    v *= uvec3(2u, 3u, 2u);
    EXPECT_EQ(v.x(), 20u);
    EXPECT_EQ(v.y(), 42u);
    EXPECT_EQ(v.z(), 36u);

    // /= (uint32_t)
    v /= 2u;
    EXPECT_EQ(v.x(), 10u);
    EXPECT_EQ(v.y(), 21u);
    EXPECT_EQ(v.z(), 18u);
}

// 5. 二項演算子のテスト (+, -, *, /)
TEST(UVec3Test, BinaryArithmetic) {
    uvec3 v1(10u, 20u, 30u);
    uvec3 v2(2u, 4u, 6u);

    // +
    uvec3 add1 = v1 + v2;
    EXPECT_EQ(add1.x(), 12u);
    EXPECT_EQ(add1.y(), 24u);
    EXPECT_EQ(add1.z(), 36u);

    uvec3 add2 = v1 + 5u;
    EXPECT_EQ(add2.x(), 15u);
    EXPECT_EQ(add2.y(), 25u);
    EXPECT_EQ(add2.z(), 35u);

    uvec3 add3 = 5u + v1;
    EXPECT_EQ(add3.x(), 15u);
    EXPECT_EQ(add3.y(), 25u);
    EXPECT_EQ(add3.z(), 35u);

    // -
    uvec3 sub1 = v1 - v2;
    EXPECT_EQ(sub1.x(), 8u);
    EXPECT_EQ(sub1.y(), 16u);
    EXPECT_EQ(sub1.z(), 24u);

    uvec3 sub2 = v1 - 5u;
    EXPECT_EQ(sub2.x(), 5u);
    EXPECT_EQ(sub2.y(), 15u);
    EXPECT_EQ(sub2.z(), 25u);

    uvec3 sub3 = 40u - v1;
    EXPECT_EQ(sub3.x(), 30u);
    EXPECT_EQ(sub3.y(), 20u);
    EXPECT_EQ(sub3.z(), 10u);

    // *
    uvec3 mul1 = v1 * v2;
    EXPECT_EQ(mul1.x(), 20u);
    EXPECT_EQ(mul1.y(), 80u);
    EXPECT_EQ(mul1.z(), 180u);

    uvec3 mul2 = v1 * 2u;
    EXPECT_EQ(mul2.x(), 20u);
    EXPECT_EQ(mul2.y(), 40u);
    EXPECT_EQ(mul2.z(), 60u);

    uvec3 mul3 = 3u * v1;
    EXPECT_EQ(mul3.x(), 30u);
    EXPECT_EQ(mul3.y(), 60u);
    EXPECT_EQ(mul3.z(), 90u);

    // /
    uvec3 div1 = v1 / v2;
    EXPECT_EQ(div1.x(), 5u);
    EXPECT_EQ(div1.y(), 5u);
    EXPECT_EQ(div1.z(), 5u);

    uvec3 div2 = v1 / 2u;
    EXPECT_EQ(div2.x(), 5u);
    EXPECT_EQ(div2.y(), 10u);
    EXPECT_EQ(div2.z(), 15u);
}

// 6. 比較演算子のテスト (<, <=, >, >=)
TEST(UVec3Test, Comparisons) {
    uvec3 v1(5u, 10u, 15u);
    uvec3 v2(10u, 10u, 10u);

    bool3 less = v1 < v2;
    EXPECT_TRUE(less.x());
    EXPECT_FALSE(less.y());
    EXPECT_FALSE(less.z());

    bool3 less_eq = v1 <= v2;
    EXPECT_TRUE(less_eq.x());
    EXPECT_TRUE(less_eq.y());
    EXPECT_FALSE(less_eq.z());

    bool3 greater = v2 > v1;
    EXPECT_TRUE(greater.x());
    EXPECT_FALSE(greater.y());
    EXPECT_FALSE(greater.z());

    bool3 greater_eq = v2 >= v1;
    EXPECT_TRUE(greater_eq.x());
    EXPECT_TRUE(greater_eq.y());
    EXPECT_FALSE(greater_eq.z());
}

// 7. ベクトル演算のテスト (length, dot, unit_vector)
TEST(UVec3Test, VectorOperations) {
    uvec3 v(2u, 3u, 6u);  // 2^2 + 3^2 + 6^2 = 4 + 9 + 36 = 49

    // 内積
    uvec3 u(1u, 2u, 3u);
    EXPECT_EQ(dot(v, u), 2u + 6u + 18u);  // 26

    // 長さと長さの2乗
    EXPECT_EQ(v.length_squared(), 49u);
    EXPECT_DOUBLE_EQ(v.length(), 7.0);  // uvec3 では double 型を返す
}