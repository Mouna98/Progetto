cmake_minimum_required(VERSION 3.13)
project(Progetto)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(unit_test)

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

set(SOURCE_FILES main.cpp)
add_executable(Progetto ${SOURCE_FILES})
add_library(core ${SOURCE_FILES})
target_link_libraries(Progetto sfml-graphics sfml-audio)
target_link_libraries(core sfml-graphics sfml-audio)

