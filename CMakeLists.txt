cmake_minimum_required(VERSION 3.17)
project(bit_of_stl)
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED)

INCLUDE_DIRECTORIES(bit_of_stl)

add_executable(bit_of_stl

#        bit_of_stl/main.cpp
        bit_of_stl/List.hpp
        bit_of_stl/Queue.hpp
        bit_of_stl/Stack.hpp
        bit_of_stl/Vector.hpp

        bit_of_stl/tests/main.cpp
        bit_of_stl/tests/vector.cpp
        bit_of_stl/tests/list.cpp

        )