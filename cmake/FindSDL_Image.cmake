# - Try to find SDL_Image
# Once done this will define
#
# SDL_Image_FOUND - system has SDL_Image
# SDL_Image_INCLUDE_DIRS - the SDL_Image include directory
# SDL_Image_LIBRARIES - the libraries needed to use SDL_Image
#
# $SDL_Image_HOME is an environment variable used for finding SDL_Image.
#
# Borrowed from The Mana World
# http://themanaworld.org/
#
# Several changes and additions by Fabian 'x3n' Landau
# Lots of simplifications by Adrian Friedli
# > www.orxonox.net <


FIND_PATH(SDL_Image_INCLUDE_DIRS SDL_Image.h
    PATHS
    $ENV{SDL_Image_HOME}
    /usr/local
    /usr
    PATH_SUFFIXES include include/SDL2
    )
IF (WIN32)
FIND_LIBRARY(SDL_Image_LIBRARIES_REL
    NAMES sdl2_Image libSDL2_Image.a
    PATHS
    $ENV{SDL_Image_HOME}/lib/Release
    $ENV{SDL_Image_HOME}/lib
    /usr/local
    /usr
    )

FIND_LIBRARY(SDL_Image_LIBRARIES_DBG
    NAMES sdl2_Image_Debug sdl2_Image libsdl2_Image.a
    PATHS
    $ENV{SDL_Image_HOME}/lib/Debug
    $ENV{SDL_Image_HOME}/lib
    /usr/local
    /usr
    )
ELSE (WIN32)
FIND_LIBRARY(SDL_Image_LIBRARY
    NAMES SDL2_Image sdl2_Image libSDL2_Image.a
    PATHS
    $ENV{SDL_Image_HOME}
    /usr/local
    /usr
    )
ENDIF (WIN32)
# handle the QUIETLY and REQUIRED arguments and set SDL_Image_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
IF (WIN32)
    FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL_Image DEFAULT_MSG SDL_Image_LIBRARIES_REL SDL_Image_LIBRARIES_DBG SDL_Image_INCLUDE_DIRS)
ELSE (WIN32)
    FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL_Image DEFAULT_MSG SDL_Image_LIBRARY SDL_Image_INCLUDE_DIRS)
ENDIF (WIN32)
IF (SDL_Image_FOUND)
    IF (WIN32)
        SET(SDL_Image_LIBRARIES optimized ${SDL_Image_LIBRARIES_REL} debug ${SDL_Image_LIBRARIES_DBG})
    ELSE (WIN32)
        SET (SDL_Image_LIBRARIES ${SDL_Image_LIBRARY})
    ENDIF (WIN32)
ELSE (SDL_Image_FOUND)
    MESSAGE("SDL_Image Not Found!")
ENDIF (SDL_Image_FOUND)

MARK_AS_ADVANCED(SDL_Image_LIBRARY SDL_Image_LIBRARIES SDL_Image_INCLUDE_DIRS)

