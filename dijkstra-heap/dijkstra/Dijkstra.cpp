#include "Dijkstra.h"

Dijkstra::Dijkstra(Graph *graph, AbstractHeap *heap, int initialVertex) {
    this->graph = graph;
    this->heap = heap;
    this->initialVertex = initialVertex;

    if(!graph->isVertexInGraph(initialVertex)) {
        std::cout << "INITIAL VERTEX " << initialVertex << " NOT EXISTS IN GRAPH" << std::endl;
        return;
    }

    initialize();
}

void Dijkstra::initialize() {
    graph->getVertex(this->initialVertex)->setDistance(0);
    heap->setVertexDistance(initialVertex, 0);
}

void Dijkstra::run() {
    // In the following loop, min position contains all nodes
    // whose shortest distance is not yet finalized.
    while (!heap->isEmpty())
    {
        Vertex* vertex = heap->pop();
//        std::cout << heap->getSize() << std::endl;

        std::vector<Edge*>* vertexEdges = vertex->getEdges();
        if(vertexEdges->empty()) {
            continue;
        }

        // Traverse through all adjacent vertices of u (the extracted
        // vertexIndex) and update their distance values
        Edge* edge = vertexEdges->back();
        int edgeDestination, edgeWeight, vertexDistance, destinationDistance;
        while (!vertexEdges->empty())
        {
            edgeDestination = edge->getDestinationVertex();
            edgeWeight = edge->getWeight();
            Vertex* destinationVertex = graph->getVertex(edgeDestination);
            vertexDistance = vertex->getDistance();
            destinationDistance = destinationVertex->getDistance();

            // If shortest distance to v is not finalized yet, and distance to v
            // through u is less than its previously calculated distance
            if (heap->isVertexInHeap(edgeDestination) && vertexDistance != INT_MAX &&
                    edgeWeight + vertexDistance < destinationDistance)
            {
                destinationVertex->setDistance(vertexDistance + edgeWeight);
                heap->setVertexDistance(edgeDestination, destinationVertex->getDistance());
            }

            vertexEdges->pop_back();
            edge = vertexEdges->back();
        }
    }
}

void Dijkstra::print() {
    std::cout << "Vertex Distance from Source" << std::endl;
    int maxVector = graph->getInitialVertex() + graph->getNumVertices();
    int vertexNum;
    for (int i = 0; i < maxVector; ++i) {
        vertexNum = i + graph->getInitialVertex();
        std::cout << vertexNum << "\t\t" << graph->getVertex(vertexNum)->getDistance() << std::endl;
    }
}
