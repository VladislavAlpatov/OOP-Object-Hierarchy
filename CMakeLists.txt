cmake_minimum_required(VERSION 3.24)
project(object_tree)

set(CMAKE_CXX_STANDARD 23)

add_executable(object_tree main.cpp)
add_subdirectory(Object)
target_sources(object_tree PRIVATE ObjectTree.cpp)