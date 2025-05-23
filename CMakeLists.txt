cmake_minimum_required(VERSION 3.28)
project(GameOfLife)


#(FindSDL2.cmake)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(SDL2 REQUIRED)


# Compiler settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()


file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "src/*.cpp")

add_library(GameOfLife_lib STATIC ${SRC_FILES})
target_include_directories(GameOfLife_lib 
                    PUBLIC 
                        "${PROJECT_SOURCE_DIR}/include"
                        ${SDL2_INCLUDE_DIR}
                        )



# Application
add_executable(${PROJECT_NAME} main.cpp)  
target_link_libraries(${PROJECT_NAME} PRIVATE GameOfLife_lib ${SDL2_LIBRARY})
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIR})
