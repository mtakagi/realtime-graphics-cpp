#include <bit>
#include <cstdint>
#include <iostream>
#include <limits>

#include "color.h"
#include "ivec2.h"
#include "uvec2.h"
#include "uvec3.h"
#include "vec2.h"
#include "vec3.h"

constexpr auto k = uvec3(0x456789abu, 0x6789ab45u, 0x89ab4567u);
constexpr auto u = uvec3(1, 2, 3);

uvec2 uhash22(uvec2 n) {
    n ^= uvec2(n.y(), n.x()) << uvec2(u.x(), u.y());
    n ^= uvec2(n.y(), n.x()) >> uvec2(u.x(), u.y());
    n *= uvec2(k.x(), k.y());
    n ^= uvec2(n.y(), n.x()) << uvec2(u.x(), u.y());

    return n * uvec2(k.x(), k.y());
}

uvec3 uhash33(uvec3 n) {
    n ^= uvec3(n.y(), n.z(), n.x()) << u;
    n ^= uvec3(n.y(), n.z(), n.x()) >> u;
    n *= k;
    n ^= uvec3(n.y(), n.z(), n.x()) << u;

    return n * k;
}

vec2 hash22(const vec2 p) {
    const auto n = uvec2(std::bit_cast<uint32_t>(static_cast<float>(p.x())),
                         std::bit_cast<uint32_t>(static_cast<float>(p.y())));
    const auto uhash = uhash22(n);

    return vec2(uhash.x(), uhash.y()) /
           vec2(std::numeric_limits<uint32_t>::max());
}

vec3 hash33(const vec3 p) {
    const auto n = uvec3(std::bit_cast<uint32_t>(static_cast<float>(p.x())),
                         std::bit_cast<uint32_t>(static_cast<float>(p.y())),
                         std::bit_cast<uint32_t>(static_cast<float>(p.z())));
    const auto uhash = uhash33(n);

    return vec3(uhash.x(), uhash.y(), uhash.z()) /
           vec3(std::numeric_limits<uint32_t>::max());
}

float hash21(const vec2 p) {
    const auto n = uvec2(std::bit_cast<uint32_t>(static_cast<float>(p.x())),
                         std::bit_cast<uint32_t>(static_cast<float>(p.y())));
    const auto uhash = uhash22(n);

    return static_cast<float>(uhash.x()) / std::numeric_limits<uint32_t>::max();
}

float hash31(const vec3 p) {
    const auto n = uvec3(std::bit_cast<uint32_t>(static_cast<float>(p.x())),
                         std::bit_cast<uint32_t>(static_cast<float>(p.y())),
                         std::bit_cast<uint32_t>(static_cast<float>(p.z())));
    const auto uhash = uhash33(n);

    return static_cast<float>(uhash.x()) / std::numeric_limits<uint32_t>::max();
}

int main() {
    constexpr auto aspect_ratio = 16.0 / 9.0;
    constexpr int width = 384;
    constexpr int height = static_cast<int>(width / aspect_ratio);
    auto time = 0.0f;

    std::cout << "P3\n" << width << ' ' << height << "\n255\n";

    for (int j = height - 1; j >= 0; --j) {
        std::cerr << "\rScan lines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < width; ++i) {
            auto u = static_cast<double>(i) / (width - 1);
            auto v = static_cast<double>(j) / (height - 1);
            auto pos = vec2(u, v) + time;
            auto channel = ivec2(u * 2, v * 2);

            if (channel.x() == 0) {
                if (channel.y() == 0) {
                    const auto color = vec3(hash21(pos));
                    write_color(std::cout, color);
                } else {
                    const auto hash = hash22(pos);
                    const auto color = vec3(hash.x(), hash.y(), 1.0);
                    write_color(std::cout, color);
                }
            } else {
                if (channel.y() == 0) {
                    const auto color =
                        vec3(hash31(vec3(pos.x(), pos.y(), time)));
                    write_color(std::cout, color);
                } else {
                    const auto hash = hash33(vec3(pos.x(), pos.y(), time));
                    write_color(std::cout, hash);
                }
            }
        }
    }
    std::cerr << "\nDone.\n";

    return 0;
}
