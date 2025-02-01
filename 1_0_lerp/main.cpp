#include <iostream>
#include "color.h"

vec3 lerp(const vec3& a, const vec3& b, double t) {
    return (1 - t) * a + t * b;
}

int main() {
    const auto aspect_ratio = 16.0 / 9.0;
    const int width = 384;
    const int height = static_cast<int>(width / aspect_ratio);

    std::cout << "P3\n" << width << ' ' << height << "\n255\n";

    for (int j = height - 1; j >= 0; --j) {
        std::cerr << "\rScan lines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < width; ++i) {
            auto u = double(i) / (width - 1);
            auto red = vec3(1.0, 0.0, 0.0);
            auto blue = vec3(0.0, 0.0, 1.0);
            auto pixel_color = lerp(red, blue, u);

            write_color(std::cout, pixel_color);
        }
    }
    std::cerr << "\nDone.\n";
    
    return 0;
}
