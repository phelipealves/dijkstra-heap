#include "HeapNode.h"

bool HeapNode::compareMinimum(HeapNode a, HeapNode b) {
    return a.getDistance() < b.getDistance();
}

void HeapNode::setDistance(int distance) {
    this->distance = distance;
}
