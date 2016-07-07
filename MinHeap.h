#ifndef DIJKSTRA_HEAP_HEAP_H
#define DIJKSTRA_HEAP_HEAP_H

#include <iostream>
#include <vector>
#include <queue>
#include "HeapNode.h"
#include "CompreMinHeap.h"


class MinHeap
{
private:
    void bubbleDown(int index);
    void bubbleUp(int index);
    void heapify();

public:
    MinHeap(int* array, int length);
    MinHeap(const std::vector<int>& vector);
    MinHeap();

    void push(int newValue);
    int top();
    int pop();
};

#endif //DIJKSTRA_HEAP_HEAP_H
