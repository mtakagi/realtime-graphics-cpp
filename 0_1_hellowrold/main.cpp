#include <iostream>
#include "color.h"

int main() {
    const auto aspect_ratio = 16.0 / 9.0;
    const int width = 384;
    const int height = static_cast<int>(width / aspect_ratio);

    std::cout << "P3\n" << width << ' ' << height << "\n255\n";

    for (int j = height - 1; j >= 0; --j) {
        std::cerr << "\rScan lines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < width; ++i) {
            auto u = double(i) / (width - 1);
            auto v = double(j) / (height - 1);
            auto color = vec3(1.0, u, v);

            write_color(std::cout, color);
        }
    }
    std::cerr << "\nDone.\n";
    
    return 0;
}
