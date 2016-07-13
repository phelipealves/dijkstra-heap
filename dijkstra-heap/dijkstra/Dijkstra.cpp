#include "Dijkstra.h"

Dijkstra::Dijkstra(Graph *graph, AbstractHeap *heap, int initialVertex) {
    this->graph = graph;
    this->heap = heap;
    this->initialVertex = initialVertex;
    vertexDistances = new std::map<int, int>();

    initialize();
}

void Dijkstra::initialize() {
    std::vector<int> vertices = graph->getVertices();
    int vertex;
    for (int i = 0; i < graph->getNumVertices(); ++i) {
        vertex = vertices.at((unsigned long) i);
        (*this->vertexDistances)[vertex] = INT_MAX;
        heap->simplePush(new HeapNode(vertex, INT_MAX));
    }

    (*this->vertexDistances)[initialVertex] = 0;
    heap->setVertexDistance(initialVertex, 0);
}

void Dijkstra::run() {
    // In the following loop, min position contains all nodes
    // whose shortest distance is not yet finalized.
    while (!heap->isEmpty())
    {
        // Extract the vertex with minimum distance value
        HeapNode node = heap->pop();
        int vertex = node.getVertex();
        std::vector<Edge*>* vertexEdges = graph->getVertexEdges(vertex);
        if(vertexEdges->empty()) {
            continue;
        }

        // Traverse through all adjacent vertices of u (the extracted
        // vertex) and update their distance values
        Edge* edge = vertexEdges->back();
        int edgeDestination, edgeWeight, vertexDistance, destinationDistance;
        while (!vertexEdges->empty())
        {
            edgeDestination = edge->getDestinationVertex();
            edgeWeight = edge->getWeight();
            vertexDistance = this->vertexDistances->at(vertex);
            destinationDistance = this->vertexDistances->at(edgeDestination);

            // If shortest distance to v is not finalized yet, and distance to v
            // through u is less than its previously calculated distance
            if (heap->isVertexInHeap(edgeDestination) && vertexDistance != INT_MAX &&
                    edgeWeight + vertexDistance < destinationDistance)
            {
                (*this->vertexDistances)[edgeDestination] = vertexDistance + edgeWeight;
                heap->setVertexDistance(edgeDestination, this->vertexDistances->at(edgeDestination));
            }

            vertexEdges->pop_back();
            edge = vertexEdges->back();
        }
    }
}

void Dijkstra::print() {
    std::cout << "Vertex Distance from Source" << std::endl;
    std::vector<int> vertices = graph->getVertices();
    int vertex;
    for (int i = 0; i < graph->getNumVertices(); ++i) {
        vertex = vertices.at((unsigned long) i);
        std::cout << vertex << "\t\t" << vertexDistances->at(vertex) << std::endl;
    }
}
