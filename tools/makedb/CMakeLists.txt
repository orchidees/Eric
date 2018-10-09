cmake_minimum_required(VERSION 3.0)

project(makedb)

SET(CMAKE_CXX_FLAGS "-Wall -g -O2 -std=c++11 -I . -Wunused-function -Wno-return-type-c-linkage")

set(binary_SOURCES makedb.cpp)

link_directories(
	${PROJECT_SOURCE_DIR}/../../src 
)

add_executable(makedb ${binary_SOURCES})

set_target_properties(makedb PROPERTIES LINK_FLAGS "-Wl,-rpath,./")

target_include_directories(dbgen
    PUBLIC 
    	${PROJECT_SOURCE_DIR}/../../src/
)

target_link_libraries(makedb
    PRIVATE orchidea
)

# post-build steps are a bit clumsy; can we do this better?? Carmine
add_custom_command(TARGET makedb POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_SOURCE_DIR}/../../build/bin/
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:dbgen> ${PROJECT_SOURCE_DIR}/../../build/bin/
)
