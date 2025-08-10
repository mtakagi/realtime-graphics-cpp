cmake_minimum_required(VERSION 3.26)
project(hsv2rgb)

set(CMAKE_CXX_STANDARD 23)

add_executable(hsv2rgb main.cpp
        vec3.h
        vec2.h
        color.h
        math.h
)
