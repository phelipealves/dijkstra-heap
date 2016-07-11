//
// Created by bruno on 7/11/16.
//

#include "DAryHeap.h"

DAryHeap::DAryHeap(int capacity, int dNumChild) {
    size = 0;
    this->dNumChild = dNumChild;
    heap = new std::vector<int>((unsigned long) (capacity + 1));
    std::fill(heap->begin(), heap->end(), -1);
}

bool DAryHeap::isEmpty() {
    return size == 0;
}

bool DAryHeap::isFull() {
    return size == heap->capacity();
}

void DAryHeap::clear() {
    size = 0;
    std::fill(heap->begin(), heap->end(), -1);
}

void DAryHeap::push(int element) {
    if(isFull()) {
        return;
    }

    heap->at((unsigned long) size++) = element;
    heapifyUp(size - 1);
}

int DAryHeap::pop() {
    if (isEmpty()) {
        return -1;
    }

    int keyItem = heap->at(0);

    heap->at(0) = heap->at((unsigned long) (size - 1));
    heap->at((unsigned long) (size - 1)) = -1;
    size--;
    heapifyDown(0);
    return keyItem;
}

int DAryHeap::top() {
    return heap->at(0);
}

void DAryHeap::print() {
    std::cout << "Heap = ";
    for(int i = 0; i < heap->capacity(); i++) {
        std::cout << heap->at((unsigned long) i) << " ";
    }
    std::cout << "\n";
}

int DAryHeap::parent(int elementIndex) {
    return (elementIndex - 1) / dNumChild;
}

int DAryHeap::kthChild(int elementIndex, int kChildIndex) {
    return (dNumChild * elementIndex) + kChildIndex;
}

void DAryHeap::heapifyUp(int elementIndex) {
    int tmp = heap->at((unsigned long) elementIndex);
    int parent;
    while (elementIndex > 0 && tmp < heap->at((unsigned long) this->parent(elementIndex)))
    {
        parent = this->parent(elementIndex);
        heap->at((unsigned long) elementIndex) = heap->at((unsigned long) parent);
        elementIndex = parent;
    }
    heap->at((unsigned long) elementIndex) = tmp;
}

void DAryHeap::heapifyDown(int elementIndex) {
    int child;
    int tmp = heap->at((unsigned long) elementIndex);
    while (kthChild(elementIndex, 1) < size)
    {
        child = minChild(elementIndex);
        if (heap->at((unsigned long) child) < tmp)
            heap->at((unsigned long) elementIndex) = heap->at((unsigned long) child);
        else
            break;
        elementIndex = child;
    }
    heap->at((unsigned long) elementIndex) = tmp;
}

int DAryHeap::minChild(int index) {
    int firstChild = kthChild(index, 1);
    int bestChild = firstChild;
    int k;
    for(k = 1; ((k < dNumChild) && ((firstChild+k) < size)); k++) {
        if (heap->at((unsigned long) (firstChild+k)) < heap->at((unsigned long) bestChild)) {
            bestChild = firstChild + k;
        }
    }
    return bestChild;
}

























