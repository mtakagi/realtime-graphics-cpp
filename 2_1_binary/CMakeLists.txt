cmake_minimum_required(VERSION 3.26)
project(binary)

set(CMAKE_CXX_STANDARD 23)

add_executable(binary main.cpp
        vec3.h
        vec2.h
        color.h
        math.h
)
