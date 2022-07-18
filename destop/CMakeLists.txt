cmake_minimum_required(VERSION 3.5)

project(freedesktop)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_BUILD_TYPE Debug)

set(exam_SOURCE
        desktop.cpp
        )

add_executable(${PROJECT_NAME} ${exam_SOURCE})

target_link_libraries(${PROJECT_NAME} simpleini)
