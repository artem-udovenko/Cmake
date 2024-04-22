#B
cmake_minimum_required(VERSION 3.10)
set(LIB BLibrary)
project(${LIB})

set(LIB_SOURCE ${PROJECT_SOURCE_DIR}/lib.cpp)

add_library(library SHARED ${LIB_SOURCE})
