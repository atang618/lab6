cmake_minimum_required(VERSION 3.3)
project(lab6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Student.cpp Student.h Catalog.cpp Catalog.h Enroll.cpp Enroll.h Course.cpp Course.h)
add_executable(lab6 ${SOURCE_FILES})
