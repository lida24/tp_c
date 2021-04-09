cmake_minimum_required(VERSION 3.8)
project(transposition_matrix)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "-pthread  -Wall -Werror -Wpedantic")
set(CMAKE_CXX_FLAGS "-pthread -Wall -Werror -Wpedantic -fprofile-arcs -ftest-coverage")
SET(MYCOMPILE_FLAGS "-std=c11")

include_directories(iz2/include)

add_library(stat STATIC
    iz2/src/consistently.c
    iz2/src/common.c
    iz2/include/interface.h)

add_library(dyn SHARED
    iz2/src/parallel.c
    iz2/src/common.c
    iz2/include/interface.h)


add_executable(static
    iz2/src/main.c)

add_executable(parallel
    iz2/src/main.c)

target_link_libraries(static stat)
target_link_libraries(parallel dyn)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})
message(${GTEST_LIBRARIES})
add_executable(test_stat
   iz2/tests/tests.cpp
   iz2/src/consistently.c
   iz2/src/common.c)

add_executable(test_parallel
   iz2/tests/tests.cpp
   iz2/src/parallel.c
   iz2/src/common.c)    
target_link_libraries(test_stat ${GTEST_LIBRARIES} stat)
target_link_libraries(test_parallel ${GTEST_LIBRARIES} dyn)
