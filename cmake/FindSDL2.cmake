# FindSDL2.cmake - кроссплатформенный модуль с поддержкой SDL2DIR
# Определяет:
#   SDL2_FOUND
#   SDL2_INCLUDE_DIR
#   SDL2_LIBRARY

message(STATUS "Looking for SDL2...")

set(_SDL2_HINT_PATHS
    $ENV{SDL2DIR}
    ${CMAKE_PREFIX_PATH}
	~/Library/Frameworks
	/Library/Frameworks
	/usr/local
	/usr
	/sw # Fink
	/opt/local # DarwinPorts
	/opt/csw # Blastwave
    /opt/homebrew
	/opt
)

# Ищем SDL.h
find_path(SDL2_INCLUDE_DIR SDL.h
  HINTS ${_SDL2_HINTS}
  PATH_SUFFIXES include include/SDL2 SDL2
)


# Ищем SDL2 библиотеку
if(APPLE)
  find_library(SDL2_LIBRARY SDL2
    HINTS ${_SDL2_HINTS}
    PATH_SUFFIXES lib SDL2
  )
else()
  find_library(SDL2_LIBRARY NAMES SDL2
    HINTS ${_SDL2_HINTS}
    PATH_SUFFIXES lib lib64
  )
endif()

# Проверка
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SDL2
  REQUIRED_VARS SDL2_LIBRARY SDL2_INCLUDE_DIR
)

# Выводим результат
if(SDL2_FOUND)
  message(STATUS "SDL2 include dir: ${SDL2_INCLUDE_DIR}")
  message(STATUS "SDL2 library: ${SDL2_LIBRARY}")
else()
  message(WARNING "SDL2 not found. You may need to set SDL2DIR manually.")
endif()