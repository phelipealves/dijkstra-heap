#include <Utils.h>
#include <d-ary-heap/DAryHeap.h>
#include "Dijkstra.h"

Dijkstra::Dijkstra(Graph *graph, AbstractHeap *heap, int initialVertex, std::string traceName) {
    this->graph = graph;
    this->heap = heap;
    this->initialVertex = initialVertex;

    if(!graph->isVertexInGraph(initialVertex)) {
        std::cout << "INITIAL VERTEX " << initialVertex << " NOT EXISTS IN GRAPH" << std::endl;
        return;
    }

    initialize();
    logFile.open (std::string("dijkstra_out_").append(traceName));
}

void Dijkstra::initialize() {
    graph->getVertex(this->initialVertex)->setDistance(0);
    heap->setVertexDistance(initialVertex, 0);
}

void Dijkstra::run() {
    // In the following loop, min position contains all nodes
    // whose shortest distance is not yet finalized.
    int iteration = 0;
    int numHeap = 1;
    while (!heap->isEmpty())
    {
        DAryHeap* daryHeap = dynamic_cast<DAryHeap*>(heap);
        logFile << ++iteration  << "\t" << numHeap << "\t" << DAryHeap::getTreeHeight(numHeap, daryHeap->getDNumChild()) << std::endl;
        Vertex* vertex = heap->pop();
        numHeap--;

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
                if (destinationDistance == INT_MAX) {
                    numHeap++;
                }
                destinationVertex->setDistance(vertexDistance + edgeWeight);
                heap->setVertexDistance(edgeDestination, destinationVertex->getDistance());
            }

            vertexEdges->pop_back();
            edge = vertexEdges->back();
        }
    }
    logFile.close();
}

void Dijkstra::print() {
    std::cout << "Vertex Distance from Source" << std::endl;
    std::cout << graph->getInitialVertex();
    int vertexNum;
    for (int i = 0; i < graph->getNumVertices(); ++i) {
        vertexNum = i + graph->getInitialVertex();
        std::cout << vertexNum << "\t\t" << graph->getVertex(vertexNum)->getDistance() << std::endl;
    }
}


