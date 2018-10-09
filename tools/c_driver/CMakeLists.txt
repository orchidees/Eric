cmake_minimum_required(VERSION 3.0)

project(c_driver)

SET(CMAKE_CXX_FLAGS "-Wall -g -O2 -std=c++11 -I . -Wunused-function -Wno-return-type-c-linkage")

set(binary_SOURCES c_driver.c)

link_directories(${PROJECT_SOURCE_DIR}/../../src)

add_executable(c_driver ${binary_SOURCES})

set_target_properties(c_driver PROPERTIES LINK_FLAGS "-Wl,-rpath,./")

target_include_directories(c_driver
    PUBLIC 
      ${PROJECT_BINARY_DIR}/../../src/
      ${PROJECT_SOURCE_DIR}/../../src/
)

target_link_libraries(c_driver
    PRIVATE orchidea_shared
)

# post-build steps are a bit clumsy; can we do this better?? Carmine
add_custom_command(TARGET c_driver POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_SOURCE_DIR}/../../build/bin/
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:c_driver> ${PROJECT_SOURCE_DIR}/../../build/bin/
)
