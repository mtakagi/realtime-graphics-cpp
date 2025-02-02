cmake_minimum_required(VERSION 3.26)
project(posterization)

set(CMAKE_CXX_STANDARD 23)

add_executable(posterization main.cpp
        vec3.h
        color.h
        vec2.h
        math.h
        bool2.h
        bool3.h
)
