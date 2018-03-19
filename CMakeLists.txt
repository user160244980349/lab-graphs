cmake_minimum_required(VERSION 3.8)
project(graph)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(graph main.cpp include/Point.h include/Line.h include/Iterator.h include/Graph.h include/PointData.h)