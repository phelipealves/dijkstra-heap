#include "CompreMinHeap.h"

bool CompareMinHeap::operator()(HeapNode &i, HeapNode &j) const {
    return i.dist > j.dist;
}
