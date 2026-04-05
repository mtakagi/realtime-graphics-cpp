cmake_minimum_required(VERSION 3.26)
project(helloworld2)

set(CMAKE_CXX_STANDARD 23)

add_executable(helloworld2 main.cpp)
target_link_libraries(helloworld2 PRIVATE common_headers)