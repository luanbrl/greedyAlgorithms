#include "binaryheap.hpp"

minHeap::minHeap(const int capacity, vector<Elements> &elements):
  capacity_{capacity}, elements_{elements} {
    buildHeap();
  }

void minHeap::heapify(int index) {
  int left = 2*index + 1;
  int right = 2*index + 2;
  int smallest = index;
  if ((left < size_) && (elements_[left].key_ < elements_[smallest].key_))
    smallest = left;
  if ((right < size_) && (elements_[right].key_ < elements_[smallest].key_))
    smallest = right;
  if (smallest != index) {
    swap(elements_[index], elements_[smallest]);
    heapify(smallest);
  }
}

void minHeap::buildHeap() {
  size_ = elements_.size();
  if (size_ <= 1)
    return;
  for (int i=(size_-2)/2; i>=0; i--) {
    heapify(i);
  }
}

inline Elements minHeap::minimum() {
  return elements_[0];
}

Elements minHeap::extractMin() {
  if (size_ < 1) {
    cout << "Empty" << endl;
    Elements null;
    return null;
  }
  Elements min = elements_[0];
  elements_[0] = elements_[size_ - 1];
  size_--;
  heapify(0);
  return min;
}

void minHeap::decrease(int index, int key) {
  if (key >= elements_[index].key_) {
    cout << "Nothing to do" << endl;
    return;
  }
  elements_[index].key_ = key;
  int parent = (index - 1)/2;
  while (index > 0 && (elements_[parent].key_ > elements_[index].key_)) {
    swap(elements_[index], elements_[parent]);
    index = parent;
    parent = (index - 1)/2;
  }
}

void minHeap::insert(int key) {
  if (size_ == capacity_) {
    cout << "Overflow" << endl;
    return;
  }
  size_++;
  elements_[size_-1].key_ = INT_MAX;
  decrease(size_-1, key);
}

int minHeap::getSize() {
  return size_;
}

void minHeap::printHeap() {
  for (int i=0; i<size_; i++) {
    cout << elements_[i].index_ << " " << elements_[i].key_ << endl;
  }
}
