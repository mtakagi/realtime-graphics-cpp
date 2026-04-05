#include <iostream>
#include <vector>

#include "color.h"
#include "mymath.h"
#include "vec2.h"

vec3 tex(vec2& st) {
    auto time = 0.2 * 0;
    auto tmp = pol2xy(vec2(time, 0.5)) + 0.5;
    auto circ = vec3(tmp.x(), tmp.y(), 1.0);
    const std::vector<color> col3 = {
        vec3(circ.x(), circ.y(), circ.z()),
        vec3(circ.y(), circ.z(), circ.x()),
        vec3(circ.z(), circ.x(), circ.y()),
    };
    st.setX(st.x() / M_PI + 1.0);
    st.setX(st.x() + time);
    auto index = static_cast<int>(st.x());
    auto col = lerp(col3[index % 2], col3[(index + 1) % 2], frac(st.x()));

    return lerp(col3[2], col, st.y());
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
            auto texture = tex(pos);
            auto x = std::min(std::max(texture.x(), 0.0), 1.0);
            auto y = std::min(std::max(texture.y(), 0.0), 1.0);
            auto z = std::min(std::max(texture.z(), 0.0), 1.0);
            write_color(std::cout, vec3(x, y, z));
        }
    }
    std::cerr << "\nDone.\n";

    return 0;
}
