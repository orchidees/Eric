cmake_minimum_required(VERSION 2.8.9)
project (anarkid)

SET(CMAKE_CXX_FLAGS "-Wall -O2 -std=c++11 -I . -Wno-return-type-c-linkage")

set (ANARKID_VERSION_MAJOR 0)
set (ANARKID_VERSION_MINOR 2)
set (MAKEDB_VERSION_MAJOR 0)
set (MAKEDB_VERSION_MINOR 2)

configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

add_executable(anarkid anarkid.cpp SoundTarget.h Source.h Parameters.h GeneticOrchestra.h Session.h OrchestrationModel.h analysis.h utilities.h constants.h)
target_link_libraries (anarkid dl ${LIBS})

add_executable(makedb makedb.cpp analysis.h utilities.h)
target_link_libraries (makedb dl ${LIBS})