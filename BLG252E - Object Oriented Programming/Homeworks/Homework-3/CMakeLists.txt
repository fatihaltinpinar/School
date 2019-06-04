cmake_minimum_required(VERSION 3.13)
project(blg252_hw3)

set(CMAKE_CXX_STANDARD 14)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/stock.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/menu.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/order.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(blg252_hw3 main.cpp)