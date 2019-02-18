# - Try to locate SDL2_image
# This module defines:
#
#  SDL2_IMAGE_INCLUDE_DIR
#  SDL2_IMAGE_LIBRARY
#  SDL2_IMAGE_FOUND
#

FIND_PATH(SDL2_IMAGE_INCLUDE_DIR NAMES SDL_image.h PATH_SUFFIXES SDL2)

FIND_LIBRARY(SDL2_IMAGE_LIBRARY NAMES SDL2_image)

INCLUDE(FindPackageHandleStandardArgs)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL2_image REQUIRED_VARS SDL2_IMAGE_LIBRARY SDL2_IMAGE_INCLUDE_DIR)

#SET( 1)

MARK_AS_ADVANCED(SDL2_IMAGE_INCLUDE_DIR SDL2_IMAGE_LIBRARY)

