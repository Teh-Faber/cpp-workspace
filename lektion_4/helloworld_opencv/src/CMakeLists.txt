cmake_minimum_required(VERSION 2.8)
project( myProject )

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( myExe main_opencv.cpp )
target_link_libraries( myExe ${OpenCV_LIBS} )
