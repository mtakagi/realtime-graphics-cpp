//
// Created by mtakagi on 2025/02/02.
//

#ifndef POSTERIZATION_BOOL2_H
#define POSTERIZATION_BOOL2_H

class bool2 {
public:
    [[nodiscard]]
    constexpr bool2() noexcept : e { false, false }  {}

    [[nodiscard]]
    constexpr bool2(bool b1, bool b2) noexcept : e { b1, b2 } {}

    [[nodiscard]]
    constexpr bool x() const {
        return e[0];
    }

    [[nodiscard]]
    constexpr bool y() const {
        return e[1];
    }

private:
    bool e[2];
};

#endif //POSTERIZATION_BOOL2_H
