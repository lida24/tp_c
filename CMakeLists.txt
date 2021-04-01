cmake_minimum_required(VERSION 3.8)
project(transposition_matrix)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "-pthread  -Wall -Werror -Wpedantic")
set(CMAKE_CXX_FLAGS "-pthread -Wall -Werror -Wpedantic -fprofile-arcs -ftest-coverage")
SET(MYCOMPILE_FLAGS "-std=c11")

include_directories(include)

add_library(stat STATIC
    src/stat.c
    include/stat.h)

add_library(dyn SHARED
    src/dyn.c
    include/stat.h)


add_executable(static
    src/main.c)

add_executable(parallel
    src/main.c)

target_link_libraries(static stat)
target_link_libraries(parallel dyn)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})
message(${GTEST_LIBRARIES})
add_executable(test_stat
   tests/tests.cpp
   src/stat.c)

add_executable(test_parallel
   tests/tests.cpp
   src/dyn.c)    
target_link_libraries(test_stat ${GTEST_LIBRARIES} stat)
target_link_libraries(test_parallel ${GTEST_LIBRARIES} dyn)


