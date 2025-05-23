
message(STATUS "Looking for SDL2...")

set(_SDL2_HINT_PATHS
    $ENV{SDL2DIR}
    ${SDL2DIR}
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

if(WIN32)
  list(APPEND _SDL2_HINT_PATHS
    "C:/libs/SDL2"
    "C:/SDL2"
    "C:/Program Files/SDL2"
    "C:/Program Files (x86)/SDL2"
  )
endif()

find_path(SDL2_INCLUDE_DIR SDL.h
  HINTS ${_SDL2_HINT_PATHS}
  PATH_SUFFIXES include include/SDL2 SDL2
)


if(APPLE)
  find_library(SDL2_LIBRARY SDL2
    HINTS ${__SDL2_HINT_PATHS}
    PATH_SUFFIXES lib SDL2
  )
else()
  find_library(SDL2_LIBRARY NAMES SDL2
    HINTS ${_SDL2_HINT_PATHS}
    PATH_SUFFIXES lib lib64 lib/x64
  )
endif()


include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SDL2
  REQUIRED_VARS SDL2_LIBRARY SDL2_INCLUDE_DIR
)

if(SDL2_FOUND)
  message(STATUS "SDL2 include dir: ${SDL2_INCLUDE_DIR}")
  message(STATUS "SDL2 library: ${SDL2_LIBRARY}")
else()
  message(WARNING "SDL2 not found. You may need to set SDL2DIR manually.")
endif()