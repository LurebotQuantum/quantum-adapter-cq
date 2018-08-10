
cmake_minimum_required (VERSION 3.8)

project ("quantum-adapter-cq")

set(CMAKE_INSTALL_PREFIX ".")

link_directories (${CMAKE_SOURCE_DIR}/lib)

add_subdirectory ("me.icefla.quantum")
