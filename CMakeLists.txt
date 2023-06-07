cmake_minimum_required(VERSION 3.10.0)

#project name
project (DoubleLinkedListCMake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)

add_executable(list main.cpp list.tpp)

target_compile_options(list PRIVATE -Wextra -Wpedantic -Werror)