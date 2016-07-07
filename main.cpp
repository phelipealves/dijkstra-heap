#include <iostream>
#include <vector>
#include <queue>
#include "HeapNode.h"
#include "CompreMinHeap.h"

using namespace std;


int main() {
    priority_queue<HeapNode, std::vector<HeapNode>, CompareMinHeap> minHeap;
    minHeap.push(HeapNode(1, 3));
    minHeap.push(HeapNode(1, 4));

    while (!minHeap.empty()) {
        cout << minHeap.top().dist << " ";
        minHeap.pop();
    }

    return 0;
}