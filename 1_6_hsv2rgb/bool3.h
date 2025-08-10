//
// Created by mtakagi on 2025/02/02.
//

#ifndef POSTERIZATION_BOOL3_H
#define POSTERIZATION_BOOL3_H

class bool3 {
public:
    [[nodiscard]]
    constexpr bool3() noexcept : e { false, false, false }  {}

    [[nodiscard]]
    constexpr bool3(bool b1, bool b2, bool b3) noexcept : e { b1, b2, b3 } {}

    [[nodiscard]]
    constexpr bool x() const {
        return e[0];
    }

    [[nodiscard]]
    constexpr bool y() const {
        return e[1];
    }

    [[nodiscard]]
    constexpr bool z() const {
        return e[2];
    }

private:
    bool e[3];
};

#endif //POSTERIZATION_BOOL3_H
