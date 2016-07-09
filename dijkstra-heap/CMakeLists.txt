cmake_minimum_required(VERSION 2.8)

project(dijkstra-heap)

add_definitions(-std=c++11)

set(HEADER_FILE
        MinHeap.h
        HeapNode.h
        CompreMinHeap.h
    )

set(SOURCE_FILES
        MinHeap.cpp
        HeapNode.cpp
        CompareMinHeap.cpp
    )

add_library(dijkstra-heap STATIC ${SOURCE_FILES} ${HEADER_FILES})

