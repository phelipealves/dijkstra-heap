#ifndef DIJKSTRA_HEAP_DIMACSGRAPHBUILDER_H
#define DIJKSTRA_HEAP_DIMACSGRAPHBUILDER_H


#include <string>
#include <fstream>
#include <iostream>
#include <cstring>
#include <graph/Graph.h>

class DimacsGraphBuilder {
public:
    static Graph* build(std::string filePath);
};


#endif //DIJKSTRA_HEAP_DIMACSGRAPHBUILDER_H
