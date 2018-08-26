cmake_minimum_required(VERSION 3.12)
project(RegularEngine)

set(CMAKE_CXX_STANDARD 14)


add_executable(RegularEngine Parser/RegexParser.cpp Parser/main.cpp)