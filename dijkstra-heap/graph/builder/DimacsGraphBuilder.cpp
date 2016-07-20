#include "DimacsGraphBuilder.h"

Graph *DimacsGraphBuilder::build() {
    char* lineType = (char *) malloc(sizeof(char) * 128);
    char* garbage = (char *) malloc(sizeof(char) * 64);
    int numVertices = 0, numEdges = 0;
    int sourceVertex, destinationVertex, weight;

    bool controlRead = false;
    while((std::cin >> lineType)) {
        if(!controlRead) {
            if(strcmp(lineType, "p") == 0) {
                std::cin >> garbage >> numVertices >> numEdges;
                free(garbage);
                controlRead = true;
                continue;
            }
        }

        if(strcmp(lineType, "a") == 0) {
            break;
        }
    }

    Graph *graph = new Graph(false, 1, numVertices);
    while((std::cin >> sourceVertex >> destinationVertex >> weight)) {
        graph->addEdge(sourceVertex, destinationVertex, weight);
        if(!(std::cin >> lineType)) {
            break;
        }
    }

    return graph;
}