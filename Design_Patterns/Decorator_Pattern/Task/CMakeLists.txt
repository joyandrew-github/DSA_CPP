
cmake_minimum_required(VERSION 3.16)

project(DecoratorPattern)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DecoratorPattern
    src/main.cpp
)

target_include_directories(DecoratorPattern
    PRIVATE include
)
