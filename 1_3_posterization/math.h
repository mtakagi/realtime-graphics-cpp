//
// Created by mtakagi on 2025/02/02.
//
// https://github.com/Unity-Technologies/Unity.Mathematics/blob/master/src/Unity.Mathematics/math.cs

#ifndef POSTERIZATION_MATH_H
#define POSTERIZATION_MATH_H

#include <cmath>
#include "vec2.h"
#include "vec3.h"
#include "bool2.h"
#include "bool3.h"

inline vec2 floor(const vec2& u) {
    return { std::floor(u.x()), std::floor(u.y()) };
}

inline vec3 floor(const vec3& u) {
    return { std::floor(u.x()), std::floor(u.y()), std::floor(u.z()) };
}

inline double frac(double x) {
    return x - floor(x);
}

inline vec2 frac(const vec2& u) {
    return u - floor(u);
}

inline vec3 frac(const vec3& u) {
    return u - floor(u);
}

inline double select(double falseValue, double trueValue, bool test) {
    return test ? trueValue : falseValue;
}

inline vec2 select(const vec2& falseValue, const vec2& trueValue, bool2 test) {
    return {test.x() ? trueValue.x() : falseValue.x(), test.y() ? trueValue.y() : falseValue.y()};
}

inline vec3 select(const vec3& falseValue, const vec3& trueValue, bool3 test) {
    return {test.x() ? trueValue.x() : falseValue.x(), test.y() ? trueValue.y() : falseValue.y(), test.z() ? trueValue.z() : falseValue.z()};
}

inline double saturate(double x) {
    return std::clamp(x, 0.0, 1.0);
}

inline vec2 saturate(const vec2& v) {
    return { std::clamp(v.x(), 0.0, 1.0), std::clamp(v.y(), 0.0, 1.0 ) };
}

inline vec3 saturate(const vec3& v) {
    return { std::clamp(v.x(), 0.0, 1.0), std::clamp(v.y(), 0.0, 1.0 ), std::clamp(v.z(), 0.0, 1.0) };
}

inline double step(double threshold, double x) {
    return select(0.0, 1.0, x >= threshold);
}

inline vec2 step(const vec2& threshold, const vec2& x) {
    return select(vec2(0,0), vec2(1, 1), x >= threshold);
}

inline vec3 step(const vec3& threshold, const vec3& x) {
    return select(vec3(0, 0, 0), vec3(1, 1, 1), x >= threshold);
}

inline double smoothstep(double xMin, double xMax, double x) {
    auto t = saturate((x - xMin) / (xMax - xMin));

    return t * t * (3.0 - (2.0 * t));
}

inline vec2 smoothstep(const vec2& xMin, const vec2& xMax, const vec2& x) {
    auto t = saturate((x - xMin) / (xMax - xMin));

    return t * t * (3.0 - (2.0 * t));
}

inline vec3 smoothstep(const vec3& xMin, const vec3& xMax, const vec3& x) {
    auto t = saturate((x - xMin) / (xMax - xMin));

    return t * t * (3.0 - (2.0 * t));
}

inline double lerp(const double a, const double b, const double t) {
    return (1 - t) * a + t * b;
}

inline vec2 lerp(const vec2& a, const vec2& b, double t) {
    return (1 - t) * a + t * b;
}

inline vec3 lerp(const vec3& a, const vec3& b, double t) {
    return (1 - t) * a + t * b;
}

#endif //POSTERIZATION_MATH_H
