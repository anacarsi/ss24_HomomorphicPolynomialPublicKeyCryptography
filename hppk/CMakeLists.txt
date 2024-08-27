cmake_minimum_required(VERSION 3.10)
project(hppk_demo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(NTL REQUIRED)

include_directories(include ${NTL_INCLUDE_DIRS})

add_executable(hppk_demo
    src/main.cpp
    src/hppk.cpp
    src/utils.cpp)

target_link_libraries(hppk_demo ${NTL_LIBRARIES})
