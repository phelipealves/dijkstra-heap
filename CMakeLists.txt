cmake_minimum_required(VERSION 3.5)
project(dijkstra-heap)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(dijkstra_run ${SOURCE_FILES})

include_directories(dijkstra-heap)

add_subdirectory(dijkstra-heap)
add_subdirectory(dijkstra-heap_test)

target_link_libraries(dijkstra_run dijkstra-heap)

