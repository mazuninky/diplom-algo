cmake_minimum_required(VERSION 3.16)
project(algo)

set(CMAKE_CXX_STANDARD 14)

add_executable(algo main.cpp
        tsan_rtl_dd_impoved.h
        tsan_rtl_dd_impoved.cpp
        sanitizer_common/sanitizer_common.h
        sanitizer_common/sanitizer_common.cpp)