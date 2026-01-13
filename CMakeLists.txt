cmake_minimum_required(VERSION 3.10)
project(PracticeTasks)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ===============================
# Практика 27
# ===============================

add_executable(Task27_1_Geometry
    task1_geometry/main.cpp
    task1_geometry/src/Circle.cpp
    task1_geometry/src/Square.cpp
    task1_geometry/src/Triangle.cpp
    task1_geometry/src/Rectangle.cpp
)
target_include_directories(Task27_1_Geometry PRIVATE task1_geometry/include)

add_executable(Task27_2_Company
    task2_company/main.cpp
    task2_company/src/Worker.cpp
    task2_company/src/Manager.cpp
    task2_company/src/Boss.cpp
    task2_company/src/Team.cpp
)
target_include_directories(Task27_2_Company PRIVATE task2_company/include)

add_executable(Task27_3_Elves
    task3_elves/main.cpp
    task3_elves/src/Branch.cpp
)
target_include_directories(Task27_3_Elves PRIVATE task3_elves/include)

# ===============================
# Практика 28
# ===============================

add_executable(Task28_1_Swimming task28_1_swimming/main.cpp)
add_executable(Task28_2_Station  task28_2_station/main.cpp)

# ===============================
# Практика 29
# ===============================

add_executable(Task29_1_SuperDog
    task29_1_superdog/main.cpp
    task29_1_superdog/Dog.cpp
)
target_include_directories(Task29_1_SuperDog PRIVATE task29_1_superdog)

add_executable(Task29_2_Shape
    task29_2_shape/main.cpp
)
target_include_directories(Task29_2_Shape PRIVATE task29_2_shape)

# ===============================
# Практика 30 (CPR)
# ===============================

find_package(cpr CONFIG REQUIRED)

add_executable(Task30_1_Requests task30_1_requests/main.cpp)
target_link_libraries(Task30_1_Requests PRIVATE cpr::cpr)

add_executable(Task30_2_HTML task30_2_html/main.cpp)
target_link_libraries(Task30_2_HTML PRIVATE cpr::cpr)

add_executable(Task30_3_Arguments task30_3_arguments/main.cpp)
target_link_libraries(Task30_3_Arguments PRIVATE cpr::cpr)