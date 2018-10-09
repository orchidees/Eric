cmake_minimum_required(VERSION 3.0)

project(orchestrate)

SET(CMAKE_CXX_FLAGS "-Wall -g2 -O2 -std=c++11 -I . -Wunused-function -Wno-return-type-c-linkage")

set(binary_SOURCES orchestrate.cpp)

link_directories(
	${PROJECT_SOURCE_DIR}/../../src 
)

add_executable(orchestrate ${binary_SOURCES})

set_target_properties(orchestrate PROPERTIES LINK_FLAGS "-Wl,-rpath,./")

target_include_directories(orchestrate
    PUBLIC 
		  ${PROJECT_BINARY_DIR}/../../src/
    	   ${PROJECT_SOURCE_DIR}/../../src/
 )

target_link_libraries(orchestrate
    PRIVATE orchidea
)

# post-build steps are a bit clumsy; can we do this better?? Carmine
add_custom_command(TARGET orchestrate POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_SOURCE_DIR}/../../build/bin/
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:orchestrate> ${PROJECT_SOURCE_DIR}/../../build/bin/
)
