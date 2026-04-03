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
  test_vec3.cpp
  test_mymath.cpp
)

# GTestのメイン関数とリンク
target_link_libraries(
  test_common
  GTest::gtest_main
)

# commonフォルダへのインクルードパスを通す
target_include_directories(test_common PRIVATE ${CMAKE_SOURCE_DIR}/common)

# CMake(CTest)にテストを認識させる
include(GoogleTest)
gtest_discover_tests(test_common)