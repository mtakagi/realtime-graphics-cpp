cmake_minimum_required(VERSION 3.26)
project(polar)

set(CMAKE_CXX_STANDARD 23)

add_executable(polar main.cpp)
target_include_directories(polar PRIVATE ${CMAKE_SOURCE_DIR}/common)