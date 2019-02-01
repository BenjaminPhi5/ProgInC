cmake_minimum_required(VERSION 3.12)
project(lab5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=[undefined] [-g] [-OX]")

include_directories(.)

add_executable(lab5
        expr.c
        expr.h
        lab5.c
        Makefile
        parse.c
        parse.h)
