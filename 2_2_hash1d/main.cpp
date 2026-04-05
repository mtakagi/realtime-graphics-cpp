#include <iostream>
#include <vector>
#include <bit>
#include <cstdint>
#include "color.h"
#include "vec2.h"
#include "vec3.h"

constexpr uint32_t k = 0x456789abu;

uint32_t uhash11(uint32_t n) {
    n ^= (n << 1);
    n ^= (n >> 1);
    n *= k;
    n ^= (n << 1);

    return n * k;
}

float hash11(float p) {
    auto n = std::bit_cast<uint32_t>(p);

    return static_cast<float>(uhash11(n)) / std::numeric_limits<uint32_t>::max();
}

int main() {
    const auto aspect_ratio = 16.0 / 9.0;
    const int width = 384;
    const int height = static_cast<int>(width / aspect_ratio);
    auto time = 0.0f;

    std::cout << "P3\n" << width << ' ' << height << "\n255\n";

    for (int j = height - 1; j >= 0; --j) {
        std::cerr << "\rScan lines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < width; ++i) {
            auto u = (double)i / (width - 1);
            auto v = (double)j / (height - 1);
            auto pos = vec2(u, v) + time;
            auto hash = hash11(pos.x());
            auto color = vec3(hash, hash, hash);          

            write_color(std::cout, color);
        }
    }
    std::cerr << "\nDone.\n";
    
    return 0;
}
