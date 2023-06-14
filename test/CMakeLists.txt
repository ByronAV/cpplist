find_package(Catch2 3 REQUIRED)
include_directories(../src)
#include_directories(src)
# These tests can use the Catch2-provided main
add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain fmt::fmt)