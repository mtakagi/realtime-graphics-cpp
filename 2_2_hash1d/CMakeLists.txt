cmake_minimum_required(VERSION 3.26)
project(hash1d)

set(CMAKE_CXX_STANDARD 23)

add_executable(hash1d main.cpp)
target_link_libraries(hash1d PRIVATE common_headers)