//
// Created by mtakagi on 2025/01/26.
//

#ifndef INONEWEEKEND_VEC3_H
#define INONEWEEKEND_VEC3_H

#include <cmath>
#include <iostream>
#include "bool3.h"

using std::sqrt;

class vec3 {
public:
    [[nodiscard]]
    constexpr vec3() : e{ 0, 0, 0 } {}

    [[nodiscard]]
    constexpr vec3(double e0) : e{ e0, e0, e0 } {}

    [[nodiscard]]
    constexpr vec3(double e0, double e1, double e2) : e{ e0, e1, e2 } {}

    [[nodiscard]]
    constexpr double x() const noexcept { return e[0]; }

    [[nodiscard]]
    constexpr double y() const noexcept { return e[1]; }

    [[nodiscard]]
    constexpr double z() const noexcept { return e[2]; }

    [[nodiscard]]
    constexpr vec3 operator-() const noexcept { return {-e[0], -e[1], -e[2]}; }

    [[nodiscard]]
    constexpr double operator[](int i) const { return e[i]; }

    [[nodiscard]]
    constexpr double& operator[](int i) { return e[i]; }

    [[nodiscard]]
    constexpr vec3& operator+=(const vec3& v) noexcept {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];

        return *this;
    }

    [[nodiscard]]
    constexpr vec3& operator*=(const double t) noexcept {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;

        return *this;
    }

    constexpr vec3& operator*=(const vec3& v) noexcept {
        e[0] *= v.x();
        e[1] *= v.y();
        e[2] *= v.z();

        return *this;
    }

    [[nodiscard]]
    constexpr vec3& operator/=(const double t) {
        return *this *= 1 / t;
    }

    [[nodiscard]]
    constexpr double length() const noexcept {
        return sqrt(length_squared());
    }

    [[nodiscard]]
    constexpr double length_squared() const noexcept {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }

private:
    double e[3];
};

using point3 = vec3;
using color = vec3;

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

[[nodiscard]]
inline vec3 operator+(const vec3& u, const vec3& v) noexcept {
    return { u.x() + v.x(), u.y() + v.y(), u.z() + v.z() };
}

[[nodiscard]]
inline vec3 operator+(double x, const vec3& v) noexcept {
    return { x + v.x(), x + v.y(), x + v.z() };
}

[[nodiscard]]
inline vec3 operator+(const vec3& v, double x) noexcept {
    return { x + v.x(), x + v.y(), x + v.z() };
}


[[nodiscard]]
inline vec3 operator-(const vec3& u, const vec3& v) noexcept {
    return { u.x() - v.x(), u.y() - v.y(), u.z() - v.z() };
}

[[nodiscard]]
inline vec3 operator-(const vec3& v, const double x) noexcept {
    return { v.x() - x, v.y() - x, v.z() - x };
}

[[nodiscard]]
inline vec3 operator-(const double x, const vec3& v) noexcept {
    return { x - v.x(), x - v.y(), x -v.z() };
}

[[nodiscard]]
inline vec3 operator*(const vec3& u, const vec3& v) noexcept {
    return { u.x() * v.x(), u.y() * v.y(), u.z() * v.z() };
}

[[nodiscard]]
inline vec3 operator*(const double t, const vec3& v) noexcept {
    return { t * v.x(), t * v.y(), t * v.z() };
}

[[nodiscard]]
inline vec3 operator*(const vec3& v, const double t) noexcept {
    return t * v;
}

[[nodiscard]]
inline vec3 operator/(const vec3& v, const double t) noexcept {
    return (1 / t) * v;
}

[[nodiscard]]
inline vec3 operator/(const vec3& u, const vec3& v) noexcept {
    return { u.x() / v.x(), u.y() / v.y(), u.z() / v.z() };
}

[[nodiscard]]
inline bool3 operator<(const vec3& u, const vec3& v) noexcept {
    return {u.x() < v.x(), u.y() < v.y(), u.z() < v.z()};
}

[[nodiscard]]
inline bool3 operator<=(const vec3& u, const vec3& v) noexcept {
    return {u.x() <= v.x(), u.y() <= v.y(), u.z() <= v.z()};
}

[[nodiscard]]
inline bool3 operator>(const vec3& u, const vec3& v) noexcept {
    return {u.x() > v.x(), u.y() > v.y(), u.z() > v.z()};
}

[[nodiscard]]
inline bool3 operator>=(const vec3& u, const vec3& v) noexcept {
    return {u.x() >= v.x(), u.y() >= v.y(), u.z() >= v.z()};
}

[[nodiscard]]
inline double dot(const vec3& u, const vec3& v) noexcept {
    return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

[[nodiscard]]
inline vec3 cross(const vec3& u, const vec3& v) noexcept {
    return {
        u.y() * v.z() - u.z() * v.y(),
        u.z() * v.x() - u.x() * v.z(),
        u.x() * v.y() - u.y() * v.x()
    };
}

[[nodiscard]]
inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}

#endif //INONEWEEKEND_VEC3_H
