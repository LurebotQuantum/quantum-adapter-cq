
cmake_minimum_required(VERSION 3.8)
project(quantum-adapter-cq)

set(PROTOS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/protos/src)

find_package(Protobuf REQUIRED)

add_subdirectory(src/protos)
add_subdirectory(src)
