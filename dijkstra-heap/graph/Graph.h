#ifndef DIJKSTRA_HEAP_GRAPH_H
#define DIJKSTRA_HEAP_GRAPH_H

#include <vector>
#include "Edge.h"
#include "Vertex.h"

class Graph {
private:
    bool undirected;
    int initialVertex;
    int numVertices;
    std::vector<Vertex*> *vertices;

    void addVertex(int begin, int end);

public:
    Graph(bool undirected, int initialVertex, int finalVertex);
    int getInitialVertex();
    int getNumVertices();
    std::vector<Vertex*>* getVertices();
    Vertex* getVertex(int vertex);
    bool isVertexInGraph(int vertex);
    void addEdge(int sourceVertex, Edge *edge);
    void addEdge(int sourceVertex, int destinationVertex, int weight);
};


#endif //DIJKSTRA_HEAP_GRAPH_H
