cmake_minimum_required(VERSION 3.30)
project(task3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task3 main.cpp)

target_link_libraries(task3
        sfml-Graphics
        sfml-Window
        sfml-System
)