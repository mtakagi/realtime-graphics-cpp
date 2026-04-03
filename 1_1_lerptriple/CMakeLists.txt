cmake_minimum_required(VERSION 3.26)
project(lerptriple)

set(CMAKE_CXX_STANDARD 23)

add_executable(lerptriple main.cpp)
target_include_directories(lerptriple PRIVATE ${CMAKE_SOURCE_DIR}/common)