cmake_minimum_required(VERSION 3.22)
project(vector_tests)

set(CMAKE_C_STANDARD 23)

add_subdirectory(lib)

include_directories(../include)
include_directories(../src)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run
        VectorTests.cpp
        ../src/Vector.hpp
        ../src/Item.cpp
        ../include/Inventario.hpp
        ../src/Inventario.cpp
)

target_link_libraries(Google_Tests_run gtest gtest_main)