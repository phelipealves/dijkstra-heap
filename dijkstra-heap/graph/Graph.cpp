#include "Graph.h"

Graph::Graph(bool undirected) {
    this->undirected = undirected;
    numVertices = 0;
    vertices = new std::vector<int>();
    vertexEdges = new std::map<int, std::vector<Edge*>>();
}

int Graph::getNumVertices() {
    return numVertices;
}

std::vector<int> Graph::getVertices() {
    return *vertices;
}

std::vector<Edge *>* Graph::getVertexEdges(int vertex) {
    return &vertexEdges->at(vertex);
}

void Graph::addVertex(int vertex) {
    if(isVertexInGraph(vertex)) {
        return;
    }

    vertices->push_back(vertex);
    (*vertexEdges)[vertex] = std::vector<Edge*>();
    numVertices++;
}

void Graph::addVertex(std::vector<int> *vertices) {
    for (int i = 0; i < vertices->size(); ++i) {
        addVertex(vertices->at((unsigned long) i));
    }
}

void Graph::addVertex(int begin, int end) {
    for (int i = begin; i <= end ; ++i) {
        addVertex(i);
    }
}

bool Graph::isVertexInGraph(int vertex) {
    return vertexEdges->count(vertex) == 1;
}

void Graph::addEdge(int sourceVertex, Edge *edge) {
    // Add source and destination vertex if not exists.
    if(!isVertexInGraph(sourceVertex)) {
        addVertex(sourceVertex);
    } else if(!isVertexInGraph(edge->getDestinationVertex())) {
        addVertex(edge->getDestinationVertex());
    }

    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    std::vector<Edge*>* vertexEdges = &this->vertexEdges->at(sourceVertex);
    vertexEdges->push_back(edge);

    // Since graph is undirected, add an edge from dest to src also
    if(undirected) {
        Edge *backEdge = new Edge(sourceVertex, edge->getWeight());
        vertexEdges = &this->vertexEdges->at(edge->getDestinationVertex());
        vertexEdges->push_back(backEdge);
    }
}

void Graph::addEdge(int sourceVertex, int destinationVertex, int weight) {
    Edge *edge = new Edge(destinationVertex, weight);
    addEdge(sourceVertex, edge);
}
