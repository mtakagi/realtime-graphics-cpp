//
// Created by mtakagi on 2026/04/06.
//

#ifndef COMMON_UVEC2_H
#define COMMON_UVEC2_H

#include <cmath>
#include <iostream>

#include "bool2.h"

using std::sqrt;

class uvec2 {
   public:
    [[nodiscard]]
    constexpr uvec2()
        : e{0, 0} {}

    [[nodiscard]]
    constexpr uvec2(uint32_t e0)
        : e{e0, e0} {}

    [[nodiscard]]
    constexpr uvec2(uint32_t e0, uint32_t e1)
        : e{e0, e1} {}

    [[nodiscard]]
    constexpr uint32_t x() const noexcept {
        return e[0];
    }

    [[nodiscard]]
    constexpr uint32_t y() const noexcept {
        return e[1];
    }

    constexpr void setX(uint32_t x) noexcept { e[0] = x; }

    constexpr void setY(uint32_t y) noexcept { e[1] = y; }

    [[nodiscard]]
    constexpr uint32_t operator[](int i) const {
        return e[i];
    }

    [[nodiscard]]
    constexpr uint32_t& operator[](int i) {
        return e[i];
    }

    constexpr uvec2& operator+=(const uvec2& v) noexcept {
        e[0] += v.e[0];
        e[1] += v.e[1];

        return *this;
    }

    constexpr uvec2& operator*=(const uint32_t t) noexcept {
        e[0] *= t;
        e[1] *= t;

        return *this;
    }

    constexpr uvec2& operator*=(const uvec2& v) noexcept {
        e[0] *= v.x();
        e[1] *= v.y();

        return *this;
    }

    constexpr uvec2& operator/=(const uint32_t t) {
        e[0] /= t;
        e[1] /= t;

        return *this;
    }

    [[nodiscard]]
    constexpr double length() const noexcept {
        return sqrt(length_squared());
    }

    [[nodiscard]]
    constexpr uint32_t length_squared() const noexcept {
        return e[0] * e[0] + e[1] * e[1];
    }

   private:
    uint32_t e[2];
};

inline std::ostream& operator<<(std::ostream& out, const uvec2& v) {
    return out << v.x() << ' ' << v.y();
}

[[nodiscard]]
inline uvec2 operator+(const uvec2& u, const uvec2& v) noexcept {
    return {u.x() + v.x(), u.y() + v.y()};
}

[[nodiscard]]
inline uvec2 operator+(const uvec2& v, const uint32_t t) noexcept {
    return {v.x() + t, v.y() + t};
}

[[nodiscard]]
inline uvec2 operator-(const uvec2& u, const uvec2& v) noexcept {
    return {u.x() - v.x(), u.y() - v.y()};
}

[[nodiscard]]
inline uvec2 operator-(const uvec2& v, const uint32_t x) noexcept {
    return {v.x() - x, v.y() - x};
}

[[nodiscard]]
inline uvec2 operator-(const uint32_t x, const uvec2& v) noexcept {
    return {x - v.x(), x - v.y()};
}

[[nodiscard]]
inline uvec2 operator*(const uvec2& u, const uvec2& v) noexcept {
    return {u.x() * v.x(), u.y() * v.y()};
}

[[nodiscard]]
inline uvec2 operator*(const uint32_t t, const uvec2& v) noexcept {
    return {t * v.x(), t * v.y()};
}

[[nodiscard]]
inline uvec2 operator*(const uvec2& v, const uint32_t t) noexcept {
    return t * v;
}

[[nodiscard]]
inline uvec2 operator/(const uvec2& v, const uint32_t t) noexcept {
    return {v.x() / t, v.y() / t};
}

[[nodiscard]]
inline uvec2 operator/(const uvec2& u, const uvec2& v) noexcept {
    return {u.x() / v.x(), u.y() / v.y()};
}

[[nodiscard]]
inline bool2 operator<(const uvec2& u, const uvec2& v) noexcept {
    return {u.x() < v.x(), u.y() < v.y()};
}

[[nodiscard]]
inline bool2 operator<=(const uvec2& u, const uvec2& v) noexcept {
    return {u.x() <= v.x(), u.y() <= v.y()};
}

[[nodiscard]]
inline bool2 operator>(const uvec2& u, const uvec2& v) noexcept {
    return {u.x() > v.x(), u.y() > v.y()};
}

[[nodiscard]]
inline bool2 operator>=(const uvec2& u, const uvec2& v) noexcept {
    return {u.x() >= v.x(), u.y() >= v.y()};
}

[[nodiscard]]
inline uint32_t dot(const uvec2& u, const uvec2& v) noexcept {
    return u.x() * v.x() + u.y() * v.y();
}

#endif  // COMMON_UVEC2_H
