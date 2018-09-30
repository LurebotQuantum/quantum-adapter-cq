
# project infomation
cmake_minimum_required(VERSION 3.8)
project(quantum-adapter-cq)

# variables
set(DIST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dist)
message(STATUS "Dist Directory = " ${DIST_DIR})

#
include_directories(include)

# the source
add_subdirectory(src)
