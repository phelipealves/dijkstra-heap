cmake_minimum_required(VERSION 3.5)
project(dijkstra_heap)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp MinHeap.cpp MinHeap.h HeapNode.cpp HeapNode.cpp HeapNode.h CompareMinHeap.cpp CompreMinHeap.h)
add_executable(dijkstra_heap ${SOURCE_FILES})