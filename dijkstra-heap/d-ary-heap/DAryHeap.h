//
// Created by bruno on 7/11/16.
//

#ifndef DIJKSTRA_HEAP_DARYHEAP_H
#define DIJKSTRA_HEAP_DARYHEAP_H

#include <iostream>
#include <vector>

class DAryHeap {
private:
    int dNumChild;
    int size;
    std::vector<int> *heap;

public:
    DAryHeap(int capacity, int dNumChild);
    bool isEmpty();
    bool isFull();
    void clear();
    void push(int element);
    int pop();
    int top();
    void print();


private:
    int parent(int elementIndex);
    int kthChild(int kChildIndex, int elementIndex);
    void heapifyUp(int elementIndex);
    void heapifyDown(int elementIndex);
    int minChild(int index);
};


#endif //DIJKSTRA_HEAP_DARYHEAP_H
