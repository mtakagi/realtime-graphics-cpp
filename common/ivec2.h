//
// Created by mtakagi on 2026/04/06.
//

#ifndef COMMON_IVEC2_H
#define COMMON_IVEC2_H

#include <cmath>
#include <cstdint>
#include <iostream>

#include "bool2.h"

class ivec2 {
   public:
    [[nodiscard]]
    constexpr ivec2()
        : e{0, 0} {}

    [[nodiscard]]
    constexpr ivec2(int32_t e0)
        : e{e0, e0} {}

    [[nodiscard]]
    constexpr ivec2(int32_t e0, int32_t e1)
        : e{e0, e1} {}

    [[nodiscard]]
    constexpr int32_t x() const noexcept {
        return e[0];
    }

    [[nodiscard]]
    constexpr int32_t y() const noexcept {
        return e[1];
    }

    constexpr void setX(int32_t x) noexcept { e[0] = x; }

    constexpr void setY(int32_t y) noexcept { e[1] = y; }

    [[nodiscard]]
    constexpr int32_t operator[](int i) const {
        return e[i];
    }

    [[nodiscard]]
    constexpr int32_t& operator[](int i) {
        return e[i];
    }

    constexpr ivec2& operator+=(const ivec2& v) noexcept {
        e[0] += v.e[0];
        e[1] += v.e[1];

        return *this;
    }

    constexpr ivec2& operator*=(const int32_t t) noexcept {
        e[0] *= t;
        e[1] *= t;

        return *this;
    }

    constexpr ivec2& operator*=(const ivec2& v) noexcept {
        e[0] *= v.x();
        e[1] *= v.y();

        return *this;
    }

    constexpr ivec2& operator/=(const int32_t t) {
        e[0] /= t;
        e[1] /= t;

        return *this;
    }

    [[nodiscard]]
    double length() const noexcept {
        return std::sqrt(static_cast<double>(length_squared()));
    }

    [[nodiscard]]
    constexpr int64_t length_squared() const noexcept {
        return static_cast<int64_t>(e[0]) * e[0] + static_cast<int64_t>(e[1]) * e[1];
    }

   private:
    int32_t e[2];
};

inline std::ostream& operator<<(std::ostream& out, const ivec2& v) {
    return out << v.x() << ' ' << v.y();
}

[[nodiscard]]
inline ivec2 operator+(const ivec2& u, const ivec2& v) noexcept {
    return {u.x() + v.x(), u.y() + v.y()};
}

[[nodiscard]]
inline ivec2 operator+(const ivec2& v, const int32_t t) noexcept {
    return {v.x() + t, v.y() + t};
}

[[nodiscard]]
inline ivec2 operator-(const ivec2& u, const ivec2& v) noexcept {
    return {u.x() - v.x(), u.y() - v.y()};
}

[[nodiscard]]
inline ivec2 operator-(const ivec2& v, const int32_t x) noexcept {
    return {v.x() - x, v.y() - x};
}

[[nodiscard]]
inline ivec2 operator-(const int32_t x, const ivec2& v) noexcept {
    return {x - v.x(), x - v.y()};
}

[[nodiscard]]
inline ivec2 operator*(const ivec2& u, const ivec2& v) noexcept {
    return {u.x() * v.x(), u.y() * v.y()};
}

[[nodiscard]]
inline ivec2 operator*(const int32_t t, const ivec2& v) noexcept {
    return {t * v.x(), t * v.y()};
}

[[nodiscard]]
inline ivec2 operator*(const ivec2& v, const int32_t t) noexcept {
    return t * v;
}

[[nodiscard]]
inline ivec2 operator/(const ivec2& v, const int32_t t) noexcept {
    return {v.x() / t, v.y() / t};
}

[[nodiscard]]
inline ivec2 operator/(const ivec2& u, const ivec2& v) noexcept {
    return {u.x() / v.x(), u.y() / v.y()};
}

[[nodiscard]]
inline bool2 operator<(const ivec2& u, const ivec2& v) noexcept {
    return {u.x() < v.x(), u.y() < v.y()};
}

[[nodiscard]]
inline bool2 operator<=(const ivec2& u, const ivec2& v) noexcept {
    return {u.x() <= v.x(), u.y() <= v.y()};
}

[[nodiscard]]
inline bool2 operator>(const ivec2& u, const ivec2& v) noexcept {
    return {u.x() > v.x(), u.y() > v.y()};
}

[[nodiscard]]
inline bool2 operator>=(const ivec2& u, const ivec2& v) noexcept {
    return {u.x() >= v.x(), u.y() >= v.y()};
}

[[nodiscard]]
inline int32_t dot(const ivec2& u, const ivec2& v) noexcept {
    return u.x() * v.x() + u.y() * v.y();
}

#endif  // COMMON_IVEC2_H
