cmake_minimum_required(VERSION 3.26)
project(polarrot)

set(CMAKE_CXX_STANDARD 23)

add_executable(polarrot main.cpp)
target_include_directories(polarrot PRIVATE ${CMAKE_SOURCE_DIR}/common)