cmake_minimum_required(VERSION 3.15)
project(test)

add_executable(test)
set(
    SRC 
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    )
target_sources(test PRIVATE ${SRC})
include_directories(${PROJECT_SOURCE_DIR}/include)