cmake_minimum_required(VERSION 3.14)

#project name
project (DoubleLinkedListCMake)

find_package(fmt REQUIRED)
include(FetchContent)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_BUILD_TYPE Debug)

add_executable(list src/main.cpp src/list.tpp)
add_subdirectory(test)

target_compile_options(list PRIVATE -Wextra -Wpedantic -Werror)
target_link_libraries(list PRIVATE fmt::fmt)