#ifndef DIJKSTRA_HEAP_HEAPNODE_H
#define DIJKSTRA_HEAP_HEAPNODE_H


class HeapNode {
public:
    int v;
    int dist;

    HeapNode(int v, int dist) : v(v), dist(dist) {}
};


#endif //DIJKSTRA_HEAP_HEAPNODE_H
