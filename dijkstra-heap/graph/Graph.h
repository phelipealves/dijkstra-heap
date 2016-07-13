#ifndef DIJKSTRA_HEAP_GRAPH_H
#define DIJKSTRA_HEAP_GRAPH_H

#include <vector>
#include <map>
#include "Edge.h"

class Graph {
private:
    bool undirected;
    int numVertices;
    std::vector<int> *vertices;
    std::map<int, std::vector<Edge*>> *vertexEdges;

public:
    Graph(bool undirected);
    int getNumVertices();
    std::vector<int> getVertices();
    std::vector<Edge*>* getVertexEdges(int vertex);

    void addVertex(int vertex);
    void addVertex(std::vector<int> *vertices);
    void addVertex(int begin, int end);
    bool isVertexInGraph(int vertex);

    // Adds an edge to an undirected graph
    void addEdge(int sourceVertex, Edge *edge);
    void addEdge(int sourceVertex, int destinationVertex, int weight);
};


#endif //DIJKSTRA_HEAP_GRAPH_H
