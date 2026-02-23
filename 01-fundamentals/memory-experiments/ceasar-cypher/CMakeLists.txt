cmake_minimum_required(VERSION 4.0)
project(ceasar-cypher)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ceasar-cypher src/main.cpp
        src/ceasar_cypher.cpp
        src/ceasar_cypher.h)