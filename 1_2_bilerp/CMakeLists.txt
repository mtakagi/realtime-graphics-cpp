cmake_minimum_required(VERSION 3.26)
project(bilerp)

set(CMAKE_CXX_STANDARD 23)

add_executable(bilerp main.cpp)
target_include_directories(bilerp PRIVATE ${CMAKE_SOURCE_DIR}/common)