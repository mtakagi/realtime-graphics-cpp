#include <iostream>
#include "color.h"
#include "vec2.h"
#include "math.h" // NOLINT

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
            auto pos = vec2(u, v);
            pos *= vec2(32.0, 9.0);
            auto a = std::vector<uint32_t> {
                static_cast<uint32_t>(time),
                0xbu,
                9u,
                0xbu ^ 9u,
                0xffffffffu,
                0xffffffffu + static_cast<uint32_t>(time),
                std::bit_cast<uint32_t>(floor(time)),
                std::bit_cast<uint32_t>(-floor(time)),
                std::bit_cast<uint32_t>(11.5625f),
            };
            vec3 color;
            if (frac(pos.x()) < 0.1) {
                if (floor(pos.x()) == 1.0) {
                    color = vec3(1, 0, 0);
                } else if (floor(pos.x()) == 9.0) {
                    color = vec3(0, 1, 0);
                } else {
                    color = vec3(0.5);
                }
            } else if (frac(pos.y()) < 0.1) {
                color = vec3(0.5);
            } else {
                auto b = a[static_cast<int>(pos.y())];
                b = (b << static_cast<uint32_t>(pos.x())) >> 31;
                color = vec3(b);
            }

            write_color(std::cout, color);
        }
    }
    std::cerr << "\nDone.\n";
    
    return 0;
}
