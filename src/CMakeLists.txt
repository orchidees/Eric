cmake_minimum_required(VERSION 2.8.9)
project (anarkid)

SET(CMAKE_CXX_FLAGS "-Wall -O2 -std=c++11 -I . -Wno-return-type-c-linkage")

add_executable(anarkid anarkid.cpp  analysis.h  ga.h constants.h  utilities.h)
target_link_libraries (anarkid dl ${LIBS})

add_executable(makedb makedb.cpp analysis.h utilities.h)
target_link_libraries (makedb dl ${LIBS})