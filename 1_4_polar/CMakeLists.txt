cmake_minimum_required(VERSION 3.26)
project(polar)

set(CMAKE_CXX_STANDARD 23)

add_executable(polar main.cpp
        vec3.h
        vec2.h
        color.h
        math.h
)
