#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<pair<int, string>> adj[100];
public:
Graph(int v){
	V = v;
}

void addVertex(string str, int v1, int v2){
	adj[v1].push_back(make_pair(v2, str));
}

void bfs(string startVertex, string destination){
	vector<bool> visited;
	visited.resize(V,false);
	queue<pair<int, string>> q;
	q.push(make_pair(0, startVertex));
	visited[0] = true;
	while(!q.empty()){
		for(auto const &i: adj[q.front().first]){
			if(!visited[i.first]){
				visited[i.first] = true;
				q.push(make_pair(i.first, i.second));
			}
		}
		cout << q.front().second << " ";
		const char *c = q.front().second.c_str();
		const char *d = destination.c_str();
		q.pop();
		if(strcmp(c, d) == 0) break;
	}
}

};
int main(){
	Graph g(20);

	g.addVertex("Rumah",0, 0);
    g.addVertex("Masjid",0, 1);
    g.addVertex("Patung macan",0, 2);
    g.addVertex("SD 3",0, 4);
    g.addVertex("Minimarket 4",2, 3);
    g.addVertex("Supermarket",2, 5);
    g.addVertex("Pasar Subuh",2, 7);
    g.addVertex("SD 2",2, 14);
    g.addVertex("SPBU 2",2, 19);
    g.addVertex("Kolam Renang",3, 6);
    g.addVertex("Minimarket 3",4, 8);
    g.addVertex("Minimarket 1",5, 9);
    g.addVertex("SD 1",6, 12);
    g.addVertex("SPBU 2",7, 19);
    g.addVertex("Pasar",8, 17);
    g.addVertex("SD 5",8, 18);
    g.addVertex("Terminal",9, 10);
    g.addVertex("Minimarket",10, 11);
    g.addVertex("Pasar",10, 17);
    g.addVertex("Hotel",11, 16);
    g.addVertex("Rumah Sakit",11, 15);
    g.addVertex("SPBU 1",12, 13);
    g.addVertex("Patung Macan",14, 2);
    g.addVertex("SD 2",15, 14);
    g.addVertex("SPBU 2",19, 19);
    
	cout << "bfs destinations" << endl;
	g.bfs("Rumah", "SPBU 1");
}