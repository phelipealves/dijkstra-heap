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
    /**
     * Constructor method.
     */
    DAryHeap(int dNumChild);

    /**
     * Returns true if the heap is empty or not otherwise.
     */
    bool isEmpty();

    /**
     * Clears the heap.
     */
    void clear();

    /**
     * Pushes some element into the heap.
     */
    void push(int element);

    /**
     * Pops the top element from the heap.
     * Returns the top element and after, removes it from the heap.
     */
    int pop();

    /**
     * Returns the top element of heap.
     */
    int top();

    /**
     * Prints the heap list.
     */
    void print();

private:
    /**
     * Returns the index of last element of heap list.
     */
    int getLastElementIndex();

    /**
     * Returns the index of parent element.
     */
    int parent(int elementIndex);

    /**
     * Returns the index of k child of element.
     */
    int kthChild(int elementIndex, int kChild);

    /**
     * Ups some element to correctly heap position.
     */
    void heapifyUp(int elementIndex);

    /**
     * Downs some element to correctly heap position.
     */
    void heapifyDown(int elementIndex);

    /**
     * Returns the minimum child of some element.
     */
    int minChild(int index);
};


#endif //DIJKSTRA_HEAP_DARYHEAP_H
