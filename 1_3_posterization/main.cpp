#include <iostream>
#include "color.h"
#include "math.h" // NOLINT

int main() {
    const auto aspect_ratio = 16.0 / 9.0;
    const int width = 384;
    const int height = static_cast<int>(width / aspect_ratio);
    const std::vector<color> col4 = {
            vec3(1.0, 0.0, 0.0),
            vec3(1.0, 1.0, 0.0),
            vec3(1.0, 0.0, 1.0),
            vec3(1.0, 1.0, 1.0),
    };

    std::cout << "P3\n" << width << ' ' << height << "\n255\n";

    int channel = 0;

    for (int j = height - 1; j >= 0; --j) {
        std::cerr << "\rScan lines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < width; ++i) {
            auto u = double(i) / (width - 1);
            auto v = double(j) / (height - 1);
            auto pos = vec2(u, v);
            const auto n = 4.0;
            channel = static_cast<int>(2.0 * u);

            pos = pos * n;

            if (channel == 0) {
                pos = floor(pos) + step(vec2(0.5, 0.5), frac(pos));
            } else {
                auto thr = 0.25 * std::sin(0.5);
                pos = floor(pos) + smoothstep(vec2(0.25 + thr, 0.25 + thr), vec2(0.75 - thr, 0.75 - thr), frac(pos));
            }

            pos = pos / n;

            auto pixel_color = lerp(lerp(col4[0], col4[1], pos.x()), lerp(col4[2], col4[3], pos.x()), pos.y());

            write_color(std::cout, pixel_color);
        }
    }
    std::cerr << "\nDone.\n";
    
    return 0;
}
