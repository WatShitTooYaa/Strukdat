#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;


// function to add edge to the graph
void addEdge(int x,int y)
{
	adj[x][y] = true;
}

// Function to perform BFS on the graph
void bfs(int start)
{
	// Visited vector to so that
	// a vertex is not visited more than once
	// Initializing the vector to false as no
	// vertex is visited at the beginning
	vector<bool> visited(adj.size(), false);
	vector<int> q;
	q.push_back(start);

	// Set source as visited
	visited[start] = true;

	int vis;
	while (!q.empty()) {
		vis = q[0];

		// Print the current node
		cout << vis << " ";
		q.erase(q.begin());

		// For every adjacent vertex to the current vertex
		for (int i = 0; i < adj[vis].size(); i++) {
			if (adj[vis][i] == 1 && (!visited[i])) {

				// Push the adjacent node to the queue
				q.push_back(i);

				// Set
				visited[i] = true;
			}
		}
	}
}

int main()
{
// number of vertices
int v = 20;


// adjacency matrix
adj= vector<vector<int>>(v,vector<int>(v,0));

  addEdge(0, 1);
  addEdge(0, 2);
  addEdge(0, 4);
  addEdge(2, 3);
  addEdge(2, 5);
  addEdge(2, 7);
  addEdge(2, 14);
  addEdge(2, 19);
  addEdge(3, 6);
  addEdge(4, 8);
  addEdge(5, 9);
  addEdge(6, 12);
  addEdge(7, 19);
  addEdge(8, 17);
  addEdge(8, 18);
  addEdge(9, 10);
  addEdge(10, 11);
  addEdge(10, 17);
  addEdge(11, 16);
  addEdge(11, 15);
  addEdge(12, 13);
  addEdge(14, 2);
  addEdge(15, 14);
    

// perform bfs on the graph
bfs(0);
}