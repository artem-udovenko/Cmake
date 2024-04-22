# main
cmake_minimum_required(VERSION 3.10)
set(MAIN TPCMake)
project(${MAIN})

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

find_package(Python COMPONENTS Interpreter REQUIRED)

add_custom_target(
  RunGenerator
  BYPRODUCTS ${PROJECT_SOURCE_DIR}/A/index.h
  COMMAND Python::Interpreter ${PROJECT_SOURCE_DIR}/A/preparing.py ${PROJECT_SOURCE_DIR}/A/index.h
  DEPENDS ${PROJECT_SOURCE_DIR}/A/preparing.py
  COMMENT "Generating index.h"
)

include_directories(${PROJECT_SOURCE_DIR})

set(MAIN_SOURCE ${PROJECT_SOURCE_DIR}/C/main.cpp)
add_executable(${MAIN} ${MAIN_SOURCE})

add_dependencies(${MAIN} RunGenerator)
target_include_directories(${MAIN} PRIVATE ${PROJECT_SOURCE_DIR})

add_subdirectory("${PROJECT_SOURCE_DIR}/B")
target_link_libraries(${MAIN} library)

find_package(GTest REQUIRED)
enable_testing()
add_executable(CTest ${PROJECT_SOURCE_DIR}/C/index_test.cpp ${PROJECT_SOURCE_DIR}/C/lib_test.cpp ${PROJECT_SOURCE_DIR}/C/main_test.cpp)

target_include_directories(CTest PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(CTest PRIVATE GTest::GTest)
add_test(Tests CTest)
add_dependencies(CTest RunGenerator)
