cmake_minimum_required(VERSION 2.8.9)
project (anarkid)

SET(CMAKE_CXX_FLAGS "-Wall -O2 -std=c++11 -I . -Wno-return-type-c-linkage")

add_executable(anarkid anarkid.cpp FFT.h   analysis.h    BMP24.h    MFCC.h   Hz2Note.h      WavFile.h      algorithms.h    constants.h     utilities.h)
target_link_libraries (anarkid dl ${LIBS})

add_executable(makedb makedb.cpp FFT.h    analysis.h     BMP24.h   MFCC.h   Hz2Note.h      WavFile.h      algorithms.h     constants.h        utilities.h)
target_link_libraries (makedb dl ${LIBS})