cmake_minimum_required(VERSION 3.5)

project(eksamens_opg LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(eksamens_opg1 main1.cpp vector3d.h)
add_executable(eksamens_opg2 main2.cpp cargo.h priority_cargo.h truck.h loading_area.h)
