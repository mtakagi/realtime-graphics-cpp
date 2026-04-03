cmake_minimum_required(VERSION 3.26)
project(hsv2rgb)

set(CMAKE_CXX_STANDARD 23)

add_executable(hsv2rgb main.cpp)
target_include_directories(hsv2rgb PRIVATE ${CMAKE_SOURCE_DIR}/common)