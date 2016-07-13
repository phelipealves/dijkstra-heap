cmake_minimum_required(VERSION 2.8)

project(dijkstra-heap)

add_definitions(-std=c++11)

set(HEADER_FILE
        AbstractHeap.h
        MinHeap.h
        HeapNode.h
        d-ary-heap/DAryHeap.h
        Utils.h
        dijkstra/Dijkstra.h
        dijkstra/Graph.h
    )

set(SOURCE_FILES
        MinHeap.cpp
        HeapNode.cpp
        d-ary-heap/DAryHeap.cpp
        Utils.cpp
        dijkstra/Dijkstra.cpp
        dijkstra/Graph.cpp
        dijkstra/Edge.h)

add_library(dijkstra-heap STATIC ${SOURCE_FILES} ${HEADER_FILES})

