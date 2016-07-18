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
        graph/Graph.h
        graph/Edge.h
        graph/builder/DimacsGraphBuilder.h
    )

set(SOURCE_FILES
        MinHeap.cpp
        HeapNode.cpp
        d-ary-heap/DAryHeap.cpp
        Utils.cpp
        dijkstra/Dijkstra.cpp
        graph/Graph.cpp
        graph/builder/DimacsGraphBuilder.cpp graph/builder/GraphBuilder.h graph/builder/GraphBuilderFactory.cpp graph/builder/GraphBuilderFactory.h)

add_library(dijkstra-heap STATIC ${SOURCE_FILES} ${HEADER_FILES})

