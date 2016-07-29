cmake_minimum_required(VERSION 2.8)

project(dijkstra-heap)

add_definitions(-std=c++11)

set(HEADER_FILE
        AbstractHeap.h
        d-ary-heap/DAryHeap.h
        Utils.h
        dijkstra/Dijkstra.h
        graph/Graph.h
        graph/Edge.h
        graph/Vertex.h
        graph/builder/DimacsGraphBuilder.h
        graph/builder/GraphBuilderFactory.h
        graph/builder/GraphBuilder.h
        cputimer/CPUTimer.h
        )

set(SOURCE_FILES
        d-ary-heap/DAryHeap.cpp
        Utils.cpp
        dijkstra/Dijkstra.cpp
        graph/Graph.cpp
        graph/builder/DimacsGraphBuilder.cpp
        graph/builder/GraphBuilderFactory.cpp
        cputimer/CPUTimer.cpp
        )

add_library(dijkstra-heap STATIC ${SOURCE_FILES} ${HEADER_FILES})

