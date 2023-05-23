cmake_minimum_required(VERSION 3.10)
project(leetcode_solutions VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/src)
include_directories(${INCLUDE_DIR})

add_library(Solutions INTERFACE)
target_include_directories(Solutions INTERFACE ${INCLUDE_DIR})

add_executable(leetcode_test main.cpp)
target_link_libraries(leetcode_test Solutions)
