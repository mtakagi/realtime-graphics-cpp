#include <iostream>
#include "color.h"
#include "vec2.h"
#include "mymath.h"

vec3 hsv2rgb(const vec3& c) {
    auto rgb = clamp(abs(fmod(c.x() * 6.0 + vec3(0.0, 4.0, 2.0), vec3(6.0)) - 3.0) - 1.0, vec3(0.0), vec3(1.0));
    return c.z() * lerp(vec3(1.0, 1.0, 1.0), rgb, c.y());
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
            auto v = double(j) / (height - 1);
            auto pos = vec2(u, v);
            pos = pos * 2.0 - 1.0;
            pos = xy2pol(pos);
            pos.setX(fmod(0.5 * pos.x() / M_PI, 1.0));
            auto rgb = hsv2rgb(vec3(pos.x(), pos.y(), 1.0));
            auto x = std::min(std::max(rgb.x(), 0.0), 1.0);
            auto y = std::min(std::max(rgb.y(), 0.0), 1.0);
            auto z = std::min(std::max(rgb.z(), 0.0), 1.0);
            write_color(std::cout, vec3(x, y, z));
        }
    }
    std::cerr << "\nDone.\n";
    
    return 0;
}
