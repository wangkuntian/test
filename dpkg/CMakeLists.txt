cmake_minimum_required(VERSION 3.5)

project(pkgverify)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_BUILD_TYPE Debug)

set(exam_SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/dpkg.cpp
        )

add_executable(${PROJECT_NAME} ${exam_SOURCE})