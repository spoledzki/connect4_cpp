cmake_minimum_required(VERSION 3.24)
project(connect4)

set(CMAKE_CXX_STANDARD 11)

add_executable(connect4 main.cpp Gra.cpp Gra.h)
