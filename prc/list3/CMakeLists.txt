cmake_minimum_required(VERSION 3.29)
project(list3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(list3
    datatype.h
    item.cpp
    item.h
    list.cpp
    list.h
    main.cpp)
