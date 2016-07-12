#include <iostream>
#include <MinHeap.h>
#include <d-ary-heap/DAryHeap.h>

using namespace std;

int main() {
    DAryHeap heap(2);
    MinHeap h(10);
    int input[8] = {10, 45, 4, 9, 16, 1, 2, 8};
    for (int i = 0; i < 8; ++i) {
        heap.push(input[i]);
        h.insertKey(input[i]);
    }
    heap.print();
    h.print();

//    cout << heap.pop() << endl;
//    heap.print();
//    cout << heap.pop() << endl;
//    heap.print();
//    cout << heap.pop() << endl;
//    heap.print();
//    cout << heap.pop() << endl;
//    heap.print();
//    cout << heap.pop() << endl;
//    heap.print();
//    cout << heap.pop() << endl;
//    heap.print();
//    cout << heap.pop() << endl;
//    heap.print();
//    cout << heap.pop() << endl;
//    heap.print();

    cout << "Finished";
    cout.flush();

    return 0;
}