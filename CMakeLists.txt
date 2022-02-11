cmake_minimum_required(VERSION 3.10)
project(swimAnnotate VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)

set(gtest_force_shared_crt on)

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(lib/googletest)