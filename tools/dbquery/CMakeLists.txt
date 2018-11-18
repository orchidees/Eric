cmake_minimum_required(VERSION 3.0)

project(dbquery)

SET(CMAKE_CXX_FLAGS "-Wall -g -O2 -std=c++11 -I . -Wunused-function -Wno-return-type-c-linkage")

set(binary_SOURCES dbquery.cpp)

link_directories(
	${PROJECT_SOURCE_DIR}/../../src 
)

add_executable(dbquery ${binary_SOURCES})

set_target_properties(dbquery PROPERTIES LINK_FLAGS "-Wl,-rpath,./")

target_include_directories(dbquery
    PUBLIC 
		${PROJECT_BINARY_DIR}/../../src/    
    	${PROJECT_SOURCE_DIR}/../../src/
)


# post-build steps are a bit clumsy; can we do this better?? Carmine
add_custom_command(TARGET dbquery POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_SOURCE_DIR}/../../build/bin/
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:dbquery> ${PROJECT_SOURCE_DIR}/../../build/bin/
)
