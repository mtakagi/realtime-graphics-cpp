cmake_minimum_required(VERSION 3.26)
project(helloworld)

set(CMAKE_CXX_STANDARD 23)

add_executable(helloworld main.cpp)
target_link_libraries(helloworld PRIVATE common_headers)