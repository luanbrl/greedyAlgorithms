#include <iostream>
#include <fstream>
#include <vector>
#include "dijkstra.hpp"

using namespace std;

void outputMatrix(const vector<vector<int>> &adj_matrix, int num_elements, ofstream &output) {
  for (int i=0; i<num_elements; i++) {
    for (int j=0; j<num_elements; j++) {
      output << adj_matrix[i][j] << " ";
    }
    output << "\n";
  }
  output << endl;
}

void outputShortestPath(const vector<int> &parents, const vector<vector<int>> &adj_matrix, ofstream &output) {
  const int size = parents.size();
  int sum = 0;
  int distance = 0;

  output << "Vértice initial = 0\n";
  output << "\nCaminhos para o vértice inicial\n\n";
  for (int i=1; i<size; i++) {
    output << i;
    for (int j=i; j!=0; ) {
      output << " > " << parents[j];
      distance += adj_matrix[j][parents[j]];
      j = parents[j];
    }
    output << "\nDistância: " << distance << "\n";
    sum += distance;
    distance = 0;
  }
  output << flush;
}

int main() {

  string fileName;
  cout << "Digite o nome do arquivo: ";
  cin >> fileName;
  string filePath = "../instancias/" + fileName;
  ifstream input(filePath);

  int n;
  vector<vector<int> > adj_matrix;

  if (input.is_open()) {
    input >> n;
    adj_matrix.resize(n, vector<int>(n));

    for (int i=0; i<n-1; i++) {
      for (int j=i+1; j<n; j++) {
        input >> adj_matrix[i][j];
        adj_matrix[j][i] = adj_matrix[i][j];
      }
    }

    input.close();
  } else cout << "Erro ao abrir o arquivo." << endl;

  vector<Elements> elements(n);
  vector<int> parents(dijkstra(adj_matrix, elements));

  ofstream output("output.txt");

  if (output.is_open()) {
    output << fileName << "\n\n";

    //outputMatrix(adj_matrix, n, output);
    outputShortestPath(parents, adj_matrix, output);

    output.close();
  } else cout << "Erro ao salvar o arquivo." << endl;

  return 0;

}
