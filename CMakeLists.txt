cmake_minimum_required(VERSION 3.26)

project(RealtimeGraphicsCpp)

set(CMAKE_CXX_STANDARD 23)

add_library(common_headers INTERFACE)
target_include_directories(common_headers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/common)

option(ENABLE_COVERAGE "Enable coverage reporting" OFF)
if(ENABLE_COVERAGE)
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
endif()

add_subdirectory(0_0_helloworld)
add_subdirectory(0_1_helloworld)
add_subdirectory(1_0_lerp)
add_subdirectory(1_1_lerptriple)
add_subdirectory(1_2_bilerp)
add_subdirectory(1_3_posterization)
add_subdirectory(1_4_polar)
add_subdirectory(1_5_polarrot)
add_subdirectory(1_6_hsv2rgb)
add_subdirectory(2_0_legacy)
add_subdirectory(2_1_binary)

enable_testing()
add_subdirectory(tests)