cmake_minimum_required(VERSION 2.8)
project( Clock )

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( myExe main.cpp clock.h clock.cpp)
target_link_libraries( myExe ${OpenCV_LIBS} )
