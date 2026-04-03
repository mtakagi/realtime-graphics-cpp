cmake_minimum_required(VERSION 3.26)
project(posterization)

set(CMAKE_CXX_STANDARD 23)

add_executable(posterization main.cpp)
target_include_directories(posterization PRIVATE ${CMAKE_SOURCE_DIR}/common)