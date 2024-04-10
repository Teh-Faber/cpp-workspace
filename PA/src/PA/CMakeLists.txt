cmake_minimum_required(VERSION 3.5)

project(PA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    PA main.cpp
    date.h)

include(GNUInstallDirs)
install(TARGETS PA
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
