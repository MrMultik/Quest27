cmake_minimum_required(VERSION 3.8)

project(Task1_Geometry)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Task1_Geometry
    main.cpp
    src/Circle.cpp
    src/Triangle.cpp
    src/Rectangle.cpp
)

target_include_directories(Task1_Geometry PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)