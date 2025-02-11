//
// Created by mtakagi on 2025/02/02.
//

#ifndef POSTERIZATION_VEC2_H
#define POSTERIZATION_VEC2_H

#include <cmath>
#include <iostream>
#include "bool2.h"

using std::sqrt;

class vec2 {
public:
    [[nodiscard]]
    constexpr vec2() : e{ 0, 0 } {}

    [[nodiscard]]
    constexpr vec2(double e0) : e{ e0, e0 } {}

    [[nodiscard]]
    constexpr vec2(double e0, double e1) : e{ e0, e1 } {}

    [[nodiscard]]
    constexpr double x() const noexcept { return e[0]; }

    [[nodiscard]]
    constexpr double y() const noexcept { return e[1]; }

    constexpr void setX(double x) noexcept {
        e[0] = x;
    }

    constexpr void setY(double y) noexcept {
        e[1] = y;
    }

    [[nodiscard]]
    constexpr vec2 operator-() const noexcept { return {-e[0], -e[1]}; }

    [[nodiscard]]
    constexpr double operator[](int i) const { return e[i]; }

    [[nodiscard]]
    constexpr double& operator[](int i) { return e[i]; }

    [[nodiscard]]
    constexpr vec2& operator+=(const vec2& v) noexcept {
        e[0] += v.e[0];
        e[1] += v.e[1];

        return *this;
    }

    [[nodiscard]]
    constexpr vec2& operator*=(const double t) noexcept {
        e[0] *= t;
        e[1] *= t;

        return *this;
    }

    constexpr vec2& operator*=(const vec2& v) noexcept {
        e[0] *= v.x();
        e[1] *= v.y();

        return *this;
    }

    [[nodiscard]]
    constexpr vec2& operator/=(const double t) {
        return *this *= 1 / t;
    }

    [[nodiscard]]
    constexpr double length() const noexcept {
        return sqrt(length_squared());
    }

    [[nodiscard]]
    constexpr double length_squared() const noexcept {
        return e[0] * e[0] + e[1] * e[1];
    }

private:
    double e[2];
};

using point2 = vec2;

inline std::ostream& operator<<(std::ostream& out, const vec2& v) {
    return out << v.x() << ' ' << v.y();
}

[[nodiscard]]
inline vec2 operator+(const vec2& u, const vec2& v) noexcept {
    return { u.x() + v.x(), u.y() + v.y() };
}

[[nodiscard]]
inline vec2 operator+(const vec2& v, const double t) noexcept {
    return { v.x() + t, v.y() + t };
}

[[nodiscard]]
inline vec2 operator-(const vec2& u, const vec2& v) noexcept {
    return { u.x() - v.x(), u.y() - v.y() };
}

[[nodiscard]]
inline vec2 operator-(const vec2& v, const double x) noexcept {
    return { v.x() - x, v.y() - x };
}

[[nodiscard]]
inline vec2 operator-(const double x, const vec2& v) noexcept {
    return { x - v.x(), x - v.y() };
}

[[nodiscard]]
inline vec2 operator*(const vec2& u, const vec2& v) noexcept {
    return { u.x() * v.x(), u.y() * v.y() };
}

[[nodiscard]]
inline vec2 operator*(const double t, const vec2& v) noexcept {
    return { t * v.x(), t * v.y() };
}

[[nodiscard]]
inline vec2 operator*(const vec2& v, const double t) noexcept {
    return t * v;
}

[[nodiscard]]
inline vec2 operator/(const vec2& v, const double t) noexcept {
    return (1 / t) * v;
}

[[nodiscard]]
inline vec2 operator/(const vec2& u, const vec2& v) noexcept {
    return { u.x() / v.x(), u.y() / v.y() };
}

[[nodiscard]]
inline bool2 operator<(const vec2& u, const vec2& v) noexcept {
    return {u.x() < v.x(), u.y() < v.y()};
}

[[nodiscard]]
inline bool2 operator<=(const vec2& u, const vec2& v) noexcept {
    return {u.x() <= v.x(), u.y() <= v.y()};
}

[[nodiscard]]
inline bool2 operator>(const vec2& u, const vec2& v) noexcept {
    return {u.x() > v.x(), u.y() > v.y()};
}

[[nodiscard]]
inline bool2 operator>=(const vec2& u, const vec2& v) noexcept {
    return {u.x() >= v.x(), u.y() >= v.y()};
}

[[nodiscard]]
inline double dot(const vec2& u, const vec2& v) noexcept {
    return u.x() * v.x() + u.y() * v.y();
}

[[nodiscard]]
inline vec2 unit_vector(vec2 v) {
    return v / v.length();
}

#endif //POSTERIZATION_VEC2_H
