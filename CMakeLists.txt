cmake_minimum_required(VERSION 3.2)
project(test2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Player.cpp Enemy.cpp)

include_directories("${PROJECT_BINARY_DIR}")
add_executable(test2 ${SOURCE_FILES})