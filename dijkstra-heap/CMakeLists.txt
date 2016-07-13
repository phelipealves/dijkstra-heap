cmake_minimum_required(VERSION 2.8)

project(dijkstra-heap)

add_definitions(-std=c++11)

set(HEADER_FILE
        MinHeap.h
        HeapNode.h
        d-ary-heap/DAryHeap.h
        Utils.h
    )

set(SOURCE_FILES
        MinHeap.cpp
        HeapNode.cpp
        d-ary-heap/DAryHeap.cpp
        Utils.cpp)

add_library(dijkstra-heap STATIC ${SOURCE_FILES} ${HEADER_FILES})

