#include "MinHeap.h"

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

// Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    int i = ++heap_size;
    harr[i] = k;
    int a = parent(i);

    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

/**
 * Method to remove minimum element (or root) from min heap
 */
int MinHeap::extractMin()
{
    if (heap_size <= 0) {
        return INT_MAX;
    }
    if (heap_size == 1) {
        heap_size--;
        return harr[MIN_HEAP_POSITION];
    }

    // Store the minimum value, and remove it from heap
    int root = harr[MIN_HEAP_POSITION];
    harr[MIN_HEAP_POSITION] = harr[heap_size];
    harr[heap_size] = INT_MIN; // clear the last item of heap
    heap_size--;
    MinHeapify(MIN_HEAP_POSITION);

    return root;
}

// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i]) {
        smallest = l;
    }
    if (r < heap_size && harr[r] < harr[smallest]) {
        smallest = r;
    }
    if (smallest != i) {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}