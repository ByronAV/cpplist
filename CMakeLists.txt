cmake_minimum_required(VERSION 3.14)

#project name
project (DoubleLinkedListCMake)

find_package(fmt REQUIRED)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_BUILD_TYPE Debug)

add_executable(${CMAKE_PROJECT_NAME} src/list.tpp src/main.cpp)
add_subdirectory(test)

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wextra -Wpedantic -Werror)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE fmt::fmt)