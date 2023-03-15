cmake_minimum_required(VERSION 3.12)

project(Week3)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O -Wall -Wextra -Wpedantic -std=c++11")
endif()

include_directories(include/
                    library/)

file(GLOB INCLUDE_DIR include/*.h)
file(GLOB IMPL_DIR library/*.cpp)

add_executable(Week3
               main.cpp
               ${INCLUDE_DIR}
               ${IMPL_DIR})