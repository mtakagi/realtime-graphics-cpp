cmake_minimum_required(VERSION 3.26)

# Google Test を自動ダウンロード
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# テスト実行ファイルの定義
add_executable(
  test_common
  test_vec2.cpp
  test_ivec2.cpp
  test_uvec2.cpp
  test_vec3.cpp
  test_uvec3.cpp
  test_mymath.cpp
)

# GTestのメイン関数とリンク
target_link_libraries(
  test_common
  PRIVATE GTest::gtest_main
)

# commonフォルダへのインクルードパスを通す
target_link_libraries(test_common PRIVATE common_headers)

# CMake(CTest)にテストを認識させる
include(GoogleTest)
gtest_discover_tests(test_common)

# Pythonのインタープリタを検索
find_package(Python3 COMPONENTS Interpreter REQUIRED)

set(GOLDEN_TEST_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/golden_test.py)
set(GOLDEN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/golden)

# ゴールデンテストを実行するターゲットのリスト
# (すべてのフォルダをテストする場合はここに追加します)
set(GOLDEN_TARGETS 
    helloworld 
    helloworld2 
    lerp 
    lerptriple 
    bilerp 
    posterization 
    polar 
    polarrot 
    hsv2rgb 
    legacy 
    binary
    hash1d
)

foreach(TARGET_NAME IN LISTS GOLDEN_TARGETS)
    add_test(
        NAME GoldenTest_${TARGET_NAME}
        COMMAND Python3::Interpreter ${GOLDEN_TEST_SCRIPT}
                $<TARGET_FILE:${TARGET_NAME}>
                ${GOLDEN_DIR}/${TARGET_NAME}.ppm
    )
endforeach()