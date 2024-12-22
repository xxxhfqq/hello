cmake_minimum_required(VERSION 3.10)
project(test)
set(CMAKE_CXX_STANDARD 11)
add_compile_options(
    "$<$<AND:$<CXX_COMPILER_ID:GNU>,$<CONFIG:Debug>>:-fexec-charset=UTF-8>"   # Debug 模式
    "$<$<AND:$<CXX_COMPILER_ID:GNU>,$<CONFIG:Release>>:-fexec-charset=GBK>" # Release 模式
)

include_directories(${PROJECT_SOURCE_DIR}/include)# include 目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# aux_source_directory(${PROJECT_SOURCE_DIR}/src/*.cpp DIR_SRCS)
file(GLOB DIR_SRCS "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_executable(${PROJECT_NAME} ${DIR_SRCS})

