cmake_minimum_required(VERSION 3.0)

project(dbgen)

SET(CMAKE_CXX_FLAGS "-Wall -g -O2 -std=c++11 -I . -Wunused-function -Wno-return-type-c-linkage")

set(binary_SOURCES dbgen.cpp)

link_directories(
	${PROJECT_SOURCE_DIR}/../../src 
)

add_executable(dbgen ${binary_SOURCES})

set_target_properties(dbgen PROPERTIES LINK_FLAGS "-Wl,-rpath,./")

target_include_directories(dbgen
    PUBLIC 
		${PROJECT_BINARY_DIR}/../../src/    
    	${PROJECT_SOURCE_DIR}/../../src/
)


# post-build steps are a bit clumsy; can we do this better?? Carmine
add_custom_command(TARGET dbgen POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_SOURCE_DIR}/../../build/bin/
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:dbgen> ${PROJECT_SOURCE_DIR}/../../build/bin/
)
