#ifndef DIJKSTRA_HEAP_GRAPHBUILDERFACTORY_H
#define DIJKSTRA_HEAP_GRAPHBUILDERFACTORY_H

#include <string>
#include "GraphBuilder.h"
#include "DimacsGraphBuilder.h"

class GraphBuilderFactory {
public:
    static GraphBuilder* getInstance(std::string driver);
};


#endif //DIJKSTRA_HEAP_GRAPHBUILDERFACTORY_H
