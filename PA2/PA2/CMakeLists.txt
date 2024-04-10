cmake_minimum_required(VERSION 3.5)

project(PA2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(PA2 main.cpp matrix.h rotmat.h)
