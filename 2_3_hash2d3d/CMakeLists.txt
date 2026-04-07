cmake_minimum_required(VERSION 3.26)
project(hash2d3d)

set(CMAKE_CXX_STANDARD 23)

add_executable(hash2d3d main.cpp)
target_link_libraries(hash2d3d PRIVATE common_headers)