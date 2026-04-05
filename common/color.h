//
// Created by mtakagi on 2025/01/27.
//

#ifndef COMMON_COLOR_H
#define COMMON_COLOR_H

#include "vec3.h"

void write_color(std::ostream& out, color pixel_color) {
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

#endif //COMMON_COLOR_H
