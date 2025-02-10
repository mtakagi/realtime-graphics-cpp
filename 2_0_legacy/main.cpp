#include <iostream>
#include "color.h"
#include "vec2.h"
#include "math.h" // NOLINT

double fractSin11(double x) {
    return frac(1000.0 * std::sin(x));
}

double fractSin21(const vec2& xy) {
    return frac(std::sin(dot(xy, vec2(12.9808, 78.233))) * 43758.5443123);
}


int main() {
    const auto aspect_ratio = 16.0 / 9.0;
    const int width = 384;
    const int height = static_cast<int>(width / aspect_ratio);

    std::cout << "P3\n" << width << ' ' << height << "\n255\n";

    for (int j = height - 1; j >= 0; --j) {
        std::cerr << "\rScan lines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < width; ++i) {
            auto pos = vec2(i, j);
            pos += floor(60.0 * 0);
            auto channel = static_cast<int>(2.0 * (double)i / (width - 1));

            if (channel == 0) {
                write_color(std::cout, fractSin11(pos.x()));
            } else {
                write_color(std::cout, fractSin21(pos / vec2(width - 1, height - 1)));
            }
        }
    }
    std::cerr << "\nDone.\n";
    
    return 0;
}
