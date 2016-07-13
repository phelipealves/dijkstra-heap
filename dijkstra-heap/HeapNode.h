#ifndef DIJKSTRA_HEAP_HEAPNODE_H
#define DIJKSTRA_HEAP_HEAPNODE_H


class HeapNode {
private:
    int vertex;
    int distance;

public:
    HeapNode(int vertex, int distance) : vertex(vertex), distance(distance) {}
    int getVertex() { return vertex; }
    int getDistance() { return distance; }
    void setDistance(int distance);

    static bool compareMinimum(HeapNode a, HeapNode b);
};


#endif //DIJKSTRA_HEAP_HEAPNODE_H
