cmake_minimum_required(VERSION 3.14)
include(FetchContent)
include_directories(src)

#project name
project (DoubleLinkedListCMake)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_BUILD_TYPE Debug)
FetchContent_Declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG master
)
FetchContent_MakeAvailable(fmt)

add_executable(list src/main.cpp src/list.tpp)

target_compile_options(list PRIVATE -Wextra -Wpedantic -Werror)
target_link_libraries(list fmt::fmt)