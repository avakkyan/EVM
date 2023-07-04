cmake_minimum_required(VERSION 3.23)
project(asm)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(asm
        asm.vcxproj
        asm.vcxproj.filters
        asm.vcxproj.user
        in1.txt
        in2.txt
        main.c
        out1.txt
        out2.txt
        sort.c
        sort.h
        test.cpp)
