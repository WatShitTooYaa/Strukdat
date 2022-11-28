#include <bits/stdc++.h>
using namespace std;

// Function to add edges
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
}

// Function to print adjacency list
void adjacencylist(vector<int> adj[], int V)
{
	for (int i = 0; i < V; i++) {
		cout << i << "->";
		for (int& x : adj[i]) {
			cout << x << " ";
		}
		cout << endl;
	}
}

// Function to initialize the adjacency list
// of the given graph
void initGraph(int V, int edges[22][19], int noOfEdges)
{
	// To represent graph as adjacency list
	vector<int> adj[V];

	// Traverse edges array and make edges
	for (int i = 0; i < noOfEdges; i++) {

		// Function call to make an edge
		addEdge(adj, edges[i][0], edges[i][1]);
	}

	// Function Call to print adjacency list
	adjacencylist(adj, V);
}

// Driver Code
int main()
{
	// Given vertices
	int V = 20;

	// Given edges
	int edges[23][19] = { 
	{ 0, 1 }, 
	{ 0, 2 }, 
	{ 0, 4 }, 
	{ 2, 3 }, 
	{ 2, 5 },
	{ 2, 7 },  
	{ 2, 14 }, 
	{ 2, 19 }, 
	{ 3, 6 }, 
	{ 4, 8 }, 
	{ 5, 9 }, 
	{ 6, 12 },
	{ 7, 19 }, 
	{ 8, 17 }, 
	{ 8, 18 }, 
	{ 9, 10 }, 
	{ 10, 11 }, 
	{ 10, 17 }, 
	{ 11, 16 }, 
	{ 11, 15 }, 
	{ 12, 13 }, 
	{ 14, 2 }, 
	{ 15, 14 }, 
	};

	int noOfEdges = 23;

	// Function Call
	initGraph(V, edges, noOfEdges);

	return 0;
}
