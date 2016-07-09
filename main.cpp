#include <iostream>
#include <MinHeap.h>
//#include "MinHeap.h"

using namespace std;


int main() {
//    priority_queue<HeapNode, std::vector<HeapNode>, CompareMinHeap> minHeap;
//    minHeap.push(HeapNode(1, 3));
//    minHeap.push(HeapNode(1, 4));
//
//    while (!minHeap.empty()) {
//        cout << minHeap.top().dist << " ";
//        minHeap.pop();
//    }

    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();

    return 0;
}