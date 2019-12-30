cmake_minimum_required(VERSION 3.10)
project(HW5)

set(CMAKE_CXX_STANDARD 14)

add_executable(HW5 StringTests.cpp
        String.h
        String.cpp
        gtest/gtest-all.cc
        gtest/gtest_main.cc
        )

#if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17 -pedantic ")
#    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address,undefined -D_GLIBCXX_DEBUG")
#endif ()
