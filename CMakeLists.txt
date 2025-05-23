cmake_minimum_required(VERSION 3.28)
project(GameOfLife)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)


find_package(SDL2 REQUIRED)
include_directories($(SDL2_INCLUDE_DIR))

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()


set(SRCS
    src/game.cpp
    src/input.cpp
    src/render.cpp
    src/main.cpp
)
add_library(GameOfLife_lib STATIC $(SRCS))
target_include_directories(GameOfLife_lib PUBLIC "include")



#find_file(SDL2_INCLUDE_DIR NAME SDL.h HINTS SDL2)
#find_library(SDL2_LIBRARY NAME SDL2)
add_executable(${PROJECT_NAME} ${SRCS})
#target_include_directories(GameOfLife ${SDL2_INCLUDE_DIR})
target_link_libraries(GameOfLife ${SDL2_LIBRARY})  
