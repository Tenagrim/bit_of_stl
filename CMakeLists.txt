cmake_minimum_required(VERSION 3.17)
project(ft_containers)
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED)

INCLUDE_DIRECTORIES(ft_containers)

add_executable(ft_containers
        ./ft_containers/main.cpp
#        ./ft_containers/List.hpp
#        ./ft_containers/List2.hpp
        ./ft_containers/Node.hpp
#        ft_containers/List3.hpp
        ft_containers/List4.hpp ft_containers/Utils.hpp ft_containers/Utils.hpp)