cmake_minimum_required(VERSION 3.28)
project(GameOfLife)


#(FindSDL2.cmake)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# Use it for direct connect
# Windows PATH SDL2
#set(SDL2DIR "PATH_TO_SDL2") e.g. PATH_TO_SDL2 = C:/libs/SDL2

# LINUX/MACOS
# set(SDL2DIR "/home/user/libs/SDL2")
# Найти SDL2 (наш FindSDL2.cmake поддерживает переменную SDL2DIR)
find_package(SDL2 REQUIRED)


# Compiler settings
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
add_library(GameOfLife_lib STATIC ${SRCS})
target_include_directories(GameOfLife_lib PUBLIC "${PROJECT_SOURCE_DIR}/include")



# Application
add_executable(${PROJECT_NAME} src/main.cpp)  
target_link_libraries(${PROJECT_NAME} PRIVATE GameOfLife_lib ${SDL2_LIBRARY})
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIR})
