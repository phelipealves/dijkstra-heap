#ifndef DIJKSTRA_HEAP_DIJKSTRA_H
#define DIJKSTRA_HEAP_DIJKSTRA_H

#include <iostream>
#include <climits>
#include <map>
#include <AbstractHeap.h>
#include "graph/Graph.h"

class Dijkstra {
private:
    Graph *graph;
    std::map<int, int> *vertexDistances;
    AbstractHeap *heap;
    int initialVertex;

    void initialize();

public:
    Dijkstra(Graph *graph, AbstractHeap *heap, int initialVertex);
    void run();
    void print();
};


#endif //DIJKSTRA_HEAP_DIJKSTRA_H
