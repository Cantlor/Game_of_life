cmake_minimum_required(VERSION 3.11)
project(GameOfLife)


set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)

find_package(SDL2 REQUIRED)


include_directories(${SDL2_INCLUDE_DIRS})
include_directories(include)

add_executable(GameOfLife
    src/main.cpp
    src/game.cpp
    src/renderer.cpp
    src/input.cpp)
target_link_libraries(GameOfLife ${SDL2_LIBRARIES})