cmake_minimum_required(VERSION 3.0)

project(orchidea)

SET(CMAKE_CXX_FLAGS "-Wall -fPIC -g2 -O2 -std=c++11 -I . -Wunused-function -Wno-return-type-c-linkage")

set (ORCHIDEA_VERSION_MAJOR 0)
set (ORCHIDEA_VERSION_MINOR 3)

configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

# Source files to be used in the library
file(GLOB library_SOURCES
    ${PROJECT_SOURCE_DIR}/*.cpp
    ${PROJECT_SOURCE_DIR}/*.h
)

#Generate the static library from the library sources
add_library(orchidea STATIC ${library_SOURCES})

#Generate the static library from the library sources
add_library(orchidea_shared SHARED ${library_SOURCES})

target_include_directories(orchidea
    PUBLIC
      ${PROJECT_SOURCE_DIR}/.
)


target_include_directories(orchidea_shared
    PUBLIC
      ${PROJECT_SOURCE_DIR}/.
)

add_custom_command(TARGET orchidea POST_BUILD
 	COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_SOURCE_DIR}/../build/bin/
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:orchidea> ${PROJECT_SOURCE_DIR}/../build/bin/
)

add_custom_command(TARGET orchidea_shared POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_SOURCE_DIR}/../build/bin/
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:orchidea_shared> ${PROJECT_SOURCE_DIR}/../build/bin/
)