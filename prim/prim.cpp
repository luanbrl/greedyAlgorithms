#include "prim.hpp"

using namespace std;

vector<int> prim(vector<vector<int>> &adj_matrix) {
  int graph_size = adj_matrix.size();
  int min_index;

  vector<Elements> elements(graph_size);
  vector<int> parents(graph_size, -1);
  vector<bool> included(graph_size, false);

  for (int i=1; i<graph_size; i++) {
    elements[i].index_ = i;
    elements[i].key_ = INT_MAX;
  }

  minHeap min_heap(graph_size, elements);

  while (min_heap.getSize()) {
    min_index = min_heap.extractMin().index_;

    included[min_index] = true;

    for (int j=0, k=0; j<graph_size; j++) {
      for (int i=0; i<graph_size; i++) {
        if (elements[i].index_ == j) {
          k = i;
          break;
        }
      }

      if ((adj_matrix[min_index][j] && !included[j]) && ((adj_matrix[min_index][j]) < elements[k].key_)) {
        parents[j] = min_index;
        min_heap.decrease(k, adj_matrix[min_index][j]);
      }
    }
  }
  return parents;
}
