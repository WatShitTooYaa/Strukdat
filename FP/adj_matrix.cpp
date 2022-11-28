#include <iostream>
using namespace std;

class Graph {
   private:
  bool** adjMatrix;
  int numVertices;

   public:
  // Initialize the matrix to zero
  Graph(int numVertices) {
    this->numVertices = numVertices;
    adjMatrix = new bool*[numVertices];
    for (int i = 0; i < numVertices; i++) {
      adjMatrix[i] = new bool[numVertices];
      for (int j = 0; j < numVertices; j++)
        adjMatrix[i][j] = false;
    }
  }

  // Add edges
  void addEdge(int i, int j) {
    adjMatrix[i][j] = true;
  }

  // Remove edges
  void removeEdge(int i, int j) {
    adjMatrix[i][j] = false;
    adjMatrix[j][i] = false;
  }

  // Print the martix
  void toString() {
    for (int i = 0; i < numVertices; i++) {
      cout << i << " : ";
      for (int j = 0; j < numVertices; j++)
        cout << adjMatrix[i][j] << " ";
      cout << "\n";
    }
  }

  Graph() {
    for (int i = 0; i < numVertices; i++)
      delete[] adjMatrix[i];
    delete[] adjMatrix;
  }
};

int main() {
  Graph g(20);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(0, 4);
  g.addEdge(2, 3);
  g.addEdge(2, 5);
  g.addEdge(2, 7);
  g.addEdge(2, 14);
  g.addEdge(2, 19);
  g.addEdge(3, 6);
  g.addEdge(4, 8);
  g.addEdge(5, 9);
  g.addEdge(6, 12);
  g.addEdge(7, 19);
  g.addEdge(8, 17);
  g.addEdge(8, 18);
  g.addEdge(9, 10);
  g.addEdge(10, 11);
  g.addEdge(10, 17);
  g.addEdge(11, 16);
  g.addEdge(11, 15);
  g.addEdge(12, 13);
  g.addEdge(14, 2);
  g.addEdge(15, 14);
  g.toString();
}