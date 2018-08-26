cmake_minimum_required(VERSION 3.12)
project(RegularEngine)

set(CMAKE_CXX_STANDARD 14)


add_executable(RegularEngine main.cpp DFARulebook.h NFARulebook.h StateTranRule.h)