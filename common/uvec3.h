//
// Created by mtakagi on 2026/04/06.
//

#ifndef COMMON_UVEC3_H
#define COMMON_UVEC3_H

#include <cmath>
#include <iostream>

#include "bool3.h"

using std::sqrt;

class uvec3 {
   public:
    [[nodiscard]]
    constexpr uvec3()
        : e{0, 0, 0} {}

    [[nodiscard]]
    constexpr uvec3(uint32_t e0)
        : e{e0, e0, e0} {}

    [[nodiscard]]
    constexpr uvec3(uint32_t e0, uint32_t e1, uint32_t e2)
        : e{e0, e1, e2} {}

    [[nodiscard]]
    constexpr uint32_t x() const noexcept {
        return e[0];
    }

    [[nodiscard]]
    constexpr uint32_t y() const noexcept {
        return e[1];
    }

    [[nodiscard]]
    constexpr uint32_t z() const noexcept {
        return e[2];
    }

    [[nodiscard]]
    constexpr uint32_t operator-() const noexcept {
        return {-e[0], -e[1], -e[2]};
    }

    [[nodiscard]]
    constexpr uint32_t operator[](int i) const {
        return e[i];
    }

    [[nodiscard]]
    constexpr uint32_t& operator[](int i) {
        return e[i];
    }

    constexpr uvec3& operator+=(const uvec3& v) noexcept {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];

        return *this;
    }

    constexpr uvec3& operator*=(const double t) noexcept {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;

        return *this;
    }

    constexpr uvec3& operator*=(const uvec3& v) noexcept {
        e[0] *= v.x();
        e[1] *= v.y();
        e[2] *= v.z();

        return *this;
    }

    constexpr uvec3& operator/=(const uint32_t t) { return *this *= 1 / t; }

    [[nodiscard]]
    constexpr double length() const noexcept {
        return sqrt(length_squared());
    }

    [[nodiscard]]
    constexpr uint32_t length_squared() const noexcept {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }

   private:
    uint32_t e[3];
};

inline std::ostream& operator<<(std::ostream& out, const uvec3& v) {
    return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

[[nodiscard]]
inline uvec3 operator+(const uvec3& u, const uvec3& v) noexcept {
    return {u.x() + v.x(), u.y() + v.y(), u.z() + v.z()};
}

[[nodiscard]]
inline uvec3 operator+(uint32_t x, const uvec3& v) noexcept {
    return {x + v.x(), x + v.y(), x + v.z()};
}

[[nodiscard]]
inline uvec3 operator+(const uvec3& v, uint32_t x) noexcept {
    return {x + v.x(), x + v.y(), x + v.z()};
}

[[nodiscard]]
inline uvec3 operator-(const uvec3& u, const uvec3& v) noexcept {
    return {u.x() - v.x(), u.y() - v.y(), u.z() - v.z()};
}

[[nodiscard]]
inline uvec3 operator-(const uvec3& v, const uint32_t x) noexcept {
    return {v.x() - x, v.y() - x, v.z() - x};
}

[[nodiscard]]
inline uvec3 operator-(const uint32_t x, const uvec3& v) noexcept {
    return {x - v.x(), x - v.y(), x - v.z()};
}

[[nodiscard]]
inline uvec3 operator*(const uvec3& u, const uvec3& v) noexcept {
    return {u.x() * v.x(), u.y() * v.y(), u.z() * v.z()};
}

[[nodiscard]]
inline uvec3 operator*(const uint32_t t, const uvec3& v) noexcept {
    return {t * v.x(), t * v.y(), t * v.z()};
}

[[nodiscard]]
inline uvec3 operator*(const uvec3& v, const uint32_t t) noexcept {
    return t * v;
}

[[nodiscard]]
inline uvec3 operator/(const uvec3& v, const uint32_t t) noexcept {
    return (1 / t) * v;
}

[[nodiscard]]
inline uvec3 operator/(const uvec3& u, const uvec3& v) noexcept {
    return {u.x() / v.x(), u.y() / v.y(), u.z() / v.z()};
}

[[nodiscard]]
inline bool3 operator<(const uvec3& u, const uvec3& v) noexcept {
    return {u.x() < v.x(), u.y() < v.y(), u.z() < v.z()};
}

[[nodiscard]]
inline bool3 operator<=(const uvec3& u, const uvec3& v) noexcept {
    return {u.x() <= v.x(), u.y() <= v.y(), u.z() <= v.z()};
}

[[nodiscard]]
inline bool3 operator>(const uvec3& u, const uvec3& v) noexcept {
    return {u.x() > v.x(), u.y() > v.y(), u.z() > v.z()};
}

[[nodiscard]]
inline bool3 operator>=(const uvec3& u, const uvec3& v) noexcept {
    return {u.x() >= v.x(), u.y() >= v.y(), u.z() >= v.z()};
}

[[nodiscard]]
inline double dot(const uvec3& u, const uvec3& v) noexcept {
    return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

[[nodiscard]]
inline uvec3 cross(const uvec3& u, const uvec3& v) noexcept {
    return {u.y() * v.z() - u.z() * v.y(), u.z() * v.x() - u.x() * v.z(),
            u.x() * v.y() - u.y() * v.x()};
}

[[nodiscard]]
inline uvec3 unit_vector(uvec3 v) {
    return v / v.length();
}

#endif //COMMON_UVEC3_H
