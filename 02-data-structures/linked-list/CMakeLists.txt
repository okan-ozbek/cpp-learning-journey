cmake_minimum_required(VERSION 4.0)
project(dsa-linked-list)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(dsa-linked-list
    src/main.cpp
    src/linked_list.cpp
    src/node.cpp
    include/linked_list.h
    include/node.h
)