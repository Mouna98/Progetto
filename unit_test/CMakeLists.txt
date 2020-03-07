cmake_minimum_required(VERSION 3.13)

add_subdirectory(./lib/googletest)

set(gtest_SOURCE_DIR ./lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../)

set(TEST_SOURCE_FILES runAllTests.cpp lib/GameCharacter.cpp lib/GameCharacter.h)
add_executable(runAllTests ${TEST_SOURCE_FILES})
target_link_libraries(runAllTests gtest gtest_main core)
