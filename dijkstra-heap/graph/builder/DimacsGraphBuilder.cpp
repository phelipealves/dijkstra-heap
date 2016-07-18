#include "DimacsGraphBuilder.h"

Graph *DimacsGraphBuilder::build() {
    Graph *graph = new Graph(false);

    char* lineType = (char *) malloc(sizeof(char) * 128);
    int sourceVertex, destinationVertex, weight;

    while((std::cin >> lineType)) {
        if(strcmp(lineType, "a") == 0) {
            std::cin >> sourceVertex >> destinationVertex >> weight;
            graph->addEdge(sourceVertex, destinationVertex, weight);
        }
    }

    return graph;
}