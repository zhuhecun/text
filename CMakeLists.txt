cmake_minimum_required(VERSION 3.29)
project(text)

# C++17
set(CMAKE_CXX_STANDARD 17)

# 定义工程文件
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# main
set(PROJECT_MAIN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
file(GLOB project_main_source_files "${PROJECT_MAIN_DIR}/*.cpp")
source_group("Source Files" FILES ${project_main_source_files})

# algorithm
set(PROJECT_ALGORITHM_DIR "${PROJECT_MAIN_DIR}/algorithm")
file(GLOB project_algorithm_source_files "${PROJECT_ALGORITHM_DIR}/*.cpp")
source_group("Algorithm Files" FILES ${project_algorithm_source_files})

# 添加可执行文件
add_executable(text ${project_main_source_files} ${project_algorithm_source_files}
        src/algorithm/parseExpress.cpp
        src/algorithm/parseExpress.h)

# 将上述文件夹 include 工程里面
include_directories(${PROJECT_MAIN_DIR} ${PROJECT_ALGORITHM_DIR})

# 生成的二进制程序
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

