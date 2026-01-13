cmake_minimum_required(VERSION 3.10)
project(PracticeTasks)

set(CMAKE_CXX_STANDARD 17)

# ===============================
# Практика 27
# ===============================

# Task 1 - Geometry
add_executable(Task1_Geometry 
    task1_geometry/main.cpp 
    task1_geometry/src/Circle.cpp 
    task1_geometry/src/Square.cpp 
    task1_geometry/src/Triangle.cpp 
    task1_geometry/src/Rectangle.cpp
)

# Task 2 - Company
add_executable(Task2_Company 
    task2_company/main.cpp 
    task2_company/src/Worker.cpp 
    task2_company/src/Manager.cpp 
    task2_company/src/Boss.cpp 
    task2_company/src/Team.cpp
)

# Task 3 - Elves
add_executable(Task3_Elves 
    task3_elves/main.cpp 
    task3_elves/src/Branch.cpp
)

# ===============================
# Практика 28 (многопоточность)
# ===============================

add_executable(Task28_1_Swimming 
    task28_1_swimming/main.cpp
)

# ===============================
# Практика 29
# ===============================

add_executable(Task29_1_SuperDog
    task29_1_superdog/main.cpp
    task29_1_superdog/Dog.cpp
)

add_executable(Task29_2_Shape
    task29_2_shape/main.cpp
)
target_include_directories(Task29_2_Shape PRIVATE task29_2_shape)