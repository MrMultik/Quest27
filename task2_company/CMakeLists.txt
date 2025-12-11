add_executable(Task2_Company
    main.cpp
    src/Worker.cpp
    src/Manager.cpp
    src/Boss.cpp
    src/Team.cpp
)

target_include_directories(Task2_Company PRIVATE include)