cmake_minimum_required(VERSION 3.7)
project(automata)

find_package(SDL2 REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/extlib/random)

include_directories(
        ${PROJECT_SOURCE_DIR}/automata/include/
        ${PROJECT_SOURCE_DIR}/automata/src/
)

file(GLOB all_srcs
        "${PROJECT_SOURCE_DIR}/automata/include/*.h"
        "${PROJECT_SOURCE_DIR}/automata/include/*.hpp"
        "${PROJECT_SOURCE_DIR}/automata/src/*.cpp")

include_directories(automata ${SDL2_INCLUDE_DIRS})

add_executable(automata automata/main.cpp ${all_srcs})
set_property(TARGET automata PROPERTY CXX_STANDARD 20)
target_link_libraries(automata ${SDL2_LIBRARIES})