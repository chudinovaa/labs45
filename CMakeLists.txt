set(CMAKE_VER 3.14)
cmake_minimum_required(VERSION ${CMAKE_VER})
project(labs45)

set(CMAKE_CXX_STANDARD 17)
include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(src)

enable_testing()
include(cmake_macros/load_gtest.cmake)
find_package(Threads REQUIRED)
add_subdirectory(test)