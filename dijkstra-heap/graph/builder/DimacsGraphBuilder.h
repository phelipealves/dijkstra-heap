#ifndef DIJKSTRA_HEAP_DIMACSGRAPHBUILDER_H
#define DIJKSTRA_HEAP_DIMACSGRAPHBUILDER_H


#include <string>
#include <fstream>
#include <iostream>
#include <cstring>
#include <graph/Graph.h>
#include "GraphBuilder.h"

class DimacsGraphBuilder: public GraphBuilder
{
public:
    virtual Graph *build() override;
};


#endif //DIJKSTRA_HEAP_DIMACSGRAPHBUILDER_H
