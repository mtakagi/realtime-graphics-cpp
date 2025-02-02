cmake_minimum_required(VERSION 3.26)
project(bilerp)

set(CMAKE_CXX_STANDARD 23)

add_executable(bilerp main.cpp
        vec3.h
        color.h
)
