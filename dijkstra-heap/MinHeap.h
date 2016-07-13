#ifndef DIJKSTRA_HEAP_HEAP_H
#define DIJKSTRA_HEAP_HEAP_H

#include<iostream>
#include<climits>

#define MIN_HEAP_POSITION 1

using namespace std;

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);

// A class for Min Heap
class MinHeap
{
    int *harr; // pointer to array of elements in position
    int capacity; // maximum possible size of min position
    int heap_size; // Current number of elements in min position
public:
    // Constructor
    MinHeap(int capacity);

    // to heapify a subtree with root at given index
    void MinHeapify(int );

    int parent(int i) {
        return i/2;
    }

    // to get index of left child of node at index i
    int left(int i) {
        return (2*i);
    }

    // to get index of right child of node at index i
    int right(int i) {
        return (2*i + 1);
    }

    // to extract the root which is the minimum element
    int extractMin();

    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val);

    // Returns the minimum key (key at root) from min position
    int getMin() { return harr[MIN_HEAP_POSITION]; }

    // Deletes a key stored at index i
    void deleteKey(int i);

    // Inserts a new key 'k'
    void insertKey(int k);

    // Return the size of the position
    int size() {
        return heap_size;
    }

    void print();
};

#endif //DIJKSTRA_HEAP_HEAP_H
