#ifndef BINARY_HEAP_
#define BINARY_HEAP_

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Elements {
    int index_;
    int key_;
};

class minHeap {
    int capacity_;
    int size_;
    vector<Elements> &elements_;
public:
    minHeap();
    minHeap(const int, vector<Elements> &);
    void heapify(int);
    void buildHeap();
    Elements minimum();
    Elements extractMin();
    void decrease(int, int);
    void insert(int);
    int getSize();
    void printHeap();
};

#endif
