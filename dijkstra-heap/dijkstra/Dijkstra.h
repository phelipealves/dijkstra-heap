#ifndef DIJKSTRA_HEAP_DIJKSTRA_H
#define DIJKSTRA_HEAP_DIJKSTRA_H

#include <iostream>
#include <climits>
#include <map>
#include <AbstractHeap.h>
#include <fstream>
#include "graph/Graph.h"

class Dijkstra {
private:
    Graph *graph;
    AbstractHeap *heap;
    int initialVertex;
    std::ofstream logFile;
    std::string traceName;

    void initialize();

public:
    Dijkstra(Graph *graph, AbstractHeap *heap, int initialVertex, std::string traceName);
    void run();
    void print();
};


#endif //DIJKSTRA_HEAP_DIJKSTRA_H
