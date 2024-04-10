cmake_minimum_required(VERSION 3.5)

project(lotr LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lotr main.cpp Character.h Weapon.h)
