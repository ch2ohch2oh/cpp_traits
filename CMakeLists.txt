cmake_minimum_required(VERSION 3.5.0)
project(cpp_traits VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

add_executable(value_meta_func value_meta_func.cpp)
add_executable(type_meta_func type_meta_func.cpp)
add_executable(func_template func_template.cpp)