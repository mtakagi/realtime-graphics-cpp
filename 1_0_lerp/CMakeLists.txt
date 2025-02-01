cmake_minimum_required(VERSION 3.26)
project(lerp)

set(CMAKE_CXX_STANDARD 23)

add_executable(lerp main.cpp
        vec3.h
        color.h
)
