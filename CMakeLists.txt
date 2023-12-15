cmake_minimum_required(VERSION 3.22)
project(ayp2_plantilla_tp1_2c2023)

set(CMAKE_C_STANDARD 23)

add_compile_options(-Wall -Werror -Wconversion)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../")
set(CXXFLAGS "-Wall -Werror -Wconversion -std=c++20")
set(CMAKE_CXX_FLAGS "${CXXFLAGS}")

include_directories(include)
include_directories(src)

add_executable(ayp2_plantilla_tp1_2c2023
        include/Vector.hpp
        src/Item.cpp
        main.cpp
        src/Inventario.cpp
        src/Menu.cpp

)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "programa.exe")