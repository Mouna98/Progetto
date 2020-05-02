cmake_minimum_required(VERSION 3.13)
project(Progetto)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(unit_test)

set(SFML_INCLUDE_DIR "./SFML/include")
set(SFML_DIR "SFML/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

set(SOURCE_FILES main.cpp GameCharacter.h GameCharacter.cpp Animation.h Animation.cpp)
add_executable(Progetto ${SOURCE_FILES})
add_library(core ${SOURCE_FILES} Entity.cpp Entity.h SpriteParameters.h AnimationManager.cpp AnimationManager.h gameValues.h)
target_link_libraries(Progetto sfml-graphics sfml-audio)
target_link_libraries(core sfml-graphics sfml-audio)

