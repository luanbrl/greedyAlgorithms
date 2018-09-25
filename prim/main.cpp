#include <iostream>
#include <fstream>
#include <vector>
#include "prim.hpp"

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

void outputMST(const vector<int> &parents, const vector<vector<int>> &adj_matrix, ofstream &output) {
  const int size = parents.size();
  int sum = 0;
  output << "Vértice raiz = 0\n";
  for (int i=1; i<size; i++) {
    output << "Vértice: " << i << " Parente: " << parents[i] << " Peso: " << adj_matrix[i][parents[i]] << endl;
    sum += adj_matrix[i][parents[i]];
  }
  output << "\nPeso Total: " << sum << endl;
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

  vector<int> parents(prim(adj_matrix));

  ofstream output("output.txt");

  if (output.is_open()) {
    output << fileName << "\n\n";

    //outputMatrix(adj_matrix, n, output);
    outputMST(parents, adj_matrix, output);

    output.close();
  } else cout << "Erro ao salvar o arquivo." << endl;

  return 0;

}
