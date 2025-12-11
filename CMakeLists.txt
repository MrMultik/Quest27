cmake_minimum_required(VERSION 3.10)
project(Quest27)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Task 1 - Geometry
add_executable(Task1_Geometry
    task1_geometry/main.cpp
    task1_geometry/src/Circle.cpp
    task1_geometry/src/Square.cpp
    task1_geometry/src/Triangle.cpp
    task1_geometry/src/Rectangle.cpp
)
target_include_directories(Task1_Geometry PRIVATE task1_geometry/include)

# Task 2 - Company
add_executable(Task2_Company
    task2_company/main.cpp
    task2_company/src/Worker.cpp
    task2_company/src/Manager.cpp
    task2_company/src/Boss.cpp
    task2_company/src/Team.cpp
)
target_include_directories(Task2_Company PRIVATE task2_company/include)

# Task 3 - Elves
add_executable(Task3_Elves
    task3_elves/main.cpp
    task3_elves/src/Branch.cpp
)
target_include_directories(Task3_Elves PRIVATE task3_elves/include)