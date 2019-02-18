cmake_minimum_required(VERSION 3.9)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(visionrayProj VERSION 0.1 DESCRIPTION "visionray lib")

# just glob the include files...
file(GLOB VSR_HEADER ${CMAKE_SOURCE_DIR}/include/*.h*)
file(GLOB VSR_SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp ${CMAKE_SOURCE_DIR}/src/*/*.cpp)

add_library(visionray STATIC
    ${VSR_SOURCES}
    ${VSR_HEADER}
)

set_target_properties(visionray PROPERTIES
	VERSION ${PROJECT_VERSION}
)

#for travis
add_compile_options("-std=c++14")

# sdl for target
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})
include_directories(${SDL2_TTF_INCLUDE_DIR})

add_library(SDL2 SHARED IMPORTED)
add_library(SDL2_ttf SHARED IMPORTED)
add_library(SDL2_image SHARED IMPORTED)

set_property(TARGET SDL2 PROPERTY IMPORTED_LOCATION ${SDL2_LIBRARY})
set_property(TARGET SDL2_ttf PROPERTY IMPORTED_LOCATION ${SDL2_TTF_LIBRARY})
set_property(TARGET SDL2_image PROPERTY IMPORTED_LOCATION ${SDL2_IMAGE_LIBRARY})

include_directories(include)

install(
    DIRECTORY ${CMAKE_SOURCE_DIR}/include/
    DESTINATION include/visionray
    FILES_MATCHING PATTERN "*.h*"
)

install(TARGETS visionray
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)
