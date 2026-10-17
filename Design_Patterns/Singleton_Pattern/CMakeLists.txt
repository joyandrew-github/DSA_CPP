
cmake_minimum_required(VERSION 3.16)

project(SingletonPattern)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SingletonPattern
    src/main.cpp
)

target_include_directories(SingletonPattern
    PRIVATE include
)
