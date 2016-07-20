#include "Graph.h"

Graph::Graph(bool undirected, int initialVertex, int finalVertex) {
    this->undirected = undirected;
    this->initialVertex = initialVertex;
    numVertices = (finalVertex - initialVertex) + 1;

    vertices = new std::vector<Vertex*>((unsigned long) (numVertices + 1));
    addVertex(initialVertex, finalVertex);
}

int Graph::getInitialVertex() {
    return initialVertex;
}

int Graph::getNumVertices() {
    return numVertices;
}

std::vector<Vertex *> *Graph::getVertices() {
    return vertices;
}

Vertex* Graph::getVertex(int vertex) {
    return (*this->vertices)[vertex-initialVertex];
}

void Graph::addVertex(int begin, int end) {
    for (int i = begin; i <= end ; ++i) {
        (*vertices)[i-initialVertex] = new Vertex(i);
    }
}

bool Graph::isVertexInGraph(int vertex) {
    return (vertex >= initialVertex && vertex < (initialVertex + numVertices));
}

void Graph::addEdge(int sourceVertex, Edge *edge) {
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    std::vector<Edge*>* vertexEdges = (*this->vertices)[sourceVertex-initialVertex]->getEdges();
    vertexEdges->push_back(edge);

    // Since graph is undirected, add an edge from dest to src also
    if(undirected) {
        Edge *backEdge = new Edge(sourceVertex, edge->getWeight());
        vertexEdges = (*this->vertices)[edge->getDestinationVertex()-initialVertex]->getEdges();
        vertexEdges->push_back(backEdge);
    }
}

void Graph::addEdge(int sourceVertex, int destinationVertex, int weight) {
    Edge *edge = new Edge(destinationVertex, weight);
    addEdge(sourceVertex, edge);
}


