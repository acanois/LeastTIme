cmake_minimum_required(VERSION 3.31)

set(PROJECT_NAME LeastTime)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

find_package(glfw3 CONFIG REQUIRED)
find_package(raylib CONFIG REQUIRED)

add_executable(${PROJECT_NAME}
    main.cpp
    scene.h
    scene.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
