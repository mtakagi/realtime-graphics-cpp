cmake_minimum_required(VERSION 3.26)
project(posterization)

set(CMAKE_CXX_STANDARD 23)

add_executable(posterization main.cpp)
target_link_libraries(posterization PRIVATE common_headers)