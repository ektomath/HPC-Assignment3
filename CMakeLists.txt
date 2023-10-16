cmake_minimum_required(VERSION 3.26)
project(Assignment3 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Assignment3
        newton.c
        parsingClargs.c)
