cmake_minimum_required(VERSION 3.12)

project(Week1)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O -Wall -Wextra -Wpedantic -std=c++11")
endif()

include_directories(bai1/
                    bai2/
                    bai3/
                    bai4/
                    bai5/)

file(GLOB BAI1_SRC bai1/*.h
                   bai1/*.cpp)
file(GLOB BAI2_SRC bai2/*.h
                   bai2/*.cpp)
file(GLOB BAI3_SRC bai3/*.h
                   bai3/*.cpp)
file(GLOB BAI4_SRC bai4/*.h
                   bai4/*.cpp)
file(GLOB BAI5_SRC bai5/*.h
                   bai5/*.cpp)

add_executable(Week1 
               main.cpp 
               ${BAI1_SRC} 
               ${BAI2_SRC} 
               ${BAI3_SRC} 
               ${BAI4_SRC} 
               ${BAI5_SRC})