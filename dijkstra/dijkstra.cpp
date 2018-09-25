#include "dijkstra.hpp"

using namespace std;

vector<int> dijkstra(const vector<vector<int>> &adj_matrix, vector<Elements> &elements) {
  int graph_size = adj_matrix.size();
  Elements min;
  int min_index;

  vector<int> parents(graph_size, -1);
  vector<bool> included(graph_size, false);

  for (int i=1; i<graph_size; i++) {
    elements[i].index_ = i;
    elements[i].key_ = INT_MAX;
  }

  minHeap min_heap(graph_size, elements);

  while (min_heap.getSize()) {
    min = min_heap.extractMin();
    min_index = min.index_;

    included[min_index] = true;

    for (int j=0, k=0; j<graph_size; j++) {
      for (int i=0; i<graph_size; i++) {
        if (elements[i].index_ == j) {
          k = i;
          break;
        }
      }

      if ((adj_matrix[min_index][j] && !included[j]) && ((adj_matrix[min_index][j] + min.key_) < elements[k].key_)) {
        parents[j] = min_index;
        min_heap.decrease(k, adj_matrix[min_index][j] + min.key_);
      }
    }
  }
  return parents;
}
