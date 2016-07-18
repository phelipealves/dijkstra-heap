#ifndef DIJKSTRA_HEAP_GRAPHBUILDER_H
#define DIJKSTRA_HEAP_GRAPHBUILDER_H

#include <graph/Graph.h>

class GraphBuilder {
public:
    virtual Graph* build() = 0;
};

#endif //DIJKSTRA_HEAP_GRAPHBUILDER_H
