#include <iostream>
#include <list>
#include <queue>
#include <string.h>
using namespace std;

class Graph{
	int V;
	int adjM[21][21] ={
          {0, 0},
          {0, 0}
    };
	string places[21];
	public:
	Graph(int v){
	    V = v;
	}
	
	void addVertex(string str, int u, int v){
	    adjM[u][v] = v;
	    places[v] = str;
	}
	
	void showAllVertex(){
	    for(int i = 0; i<V;i++){
	        for(int j = 1; j<=V;j++){
	            if(adjM[i][j] == 0) cout << ".  ";
	            else if (adjM[i][j] < 10) cout << adjM[i][j] << "  ";
	            else cout << adjM[i][j] << " ";
	        }
	        cout <<  endl;
	    }
	}
	
	bool shortest_path(int strt, int end, int pred[], int dist[]){
	queue<int> q;
	bool visited[V] = {false};
	dist[21] = {0};
	pred[21] = {-1};
	visited[strt] = true;
	dist[strt] = 0;
	q.push(strt);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 1; i<=V; i++){
			if(visited[i] == false && adjM[u][i] != 0){
				visited[i] = true;
				dist[i] = dist[u] + 1;
				pred[i] = u;
				cout << u << " " << i << endl;
				q.push(i);
				if(i == end){
                    return true;
                }    
			}
		}
	}
	return false;
}
    
    void shortestPath(int strt, int end){
		int pred[V], dist[V];
		shortest_path(strt, end, pred, dist);
		vector<int> path;
		int c = end;
		path.push_back(c);
		while(pred[c] != 0){
			path.push_back(pred[c]);
			c = pred[c];
		}
		for(int i = path.size() - 1; i >= 0; i--){
			cout << path[i] << " " << places[path[i]] << endl;
		}
}
};
int main(){
	Graph g(20);
	g.addVertex("Rumah",0, 0);
    g.addVertex("Masjid",0, 1);
    g.addVertex("Patung Macan",0, 2);
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
	g.showAllVertex();
	int start, end;
	cin >> start >> end;
    g.shortestPath(start,end);
}