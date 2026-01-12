cmake_minimum_required(VERSION 3.10)
project(PracticeTasks)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

# ===============================
# Практика 28 (многопоточность)
# ===============================

# Task 28.1 - Swimming
add_executable(Task28_1_Swimming 
    task28_1_swimming/main.cpp
)

# Task 28.2 - Station
add_executable(Task28_2_Station 
    task28_2_station/main.cpp
)

# Task 28.3 - Kitchen удален

# ===============================
# Практика 29
# ===============================

# Task 29.1 - SuperDog
add_executable(Task29_1_SuperDog
    task29_1_superdog/main.cpp
    task29_1_superdog/Dog.cpp
)
target_include_directories(Task29_1_SuperDog PRIVATE task29_1_superdog)

# Task 29.2 - Shape
add_executable(Task29_2_Shape
    task29_2_shape/main.cpp
)
target_include_directories(Task29_2_Shape PRIVATE task29_2_shape)