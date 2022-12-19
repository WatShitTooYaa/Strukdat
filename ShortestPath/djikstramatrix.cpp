#include <iostream>
#include <list>
#include <queue>
#include <string.h>
using namespace std;
typedef pair<int,int> intPair;

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
	
	void addVertex(string str, int u, int v, int w){
	    adjM[u][v] = w;
	    places[v] = str;
	}

	void showAllVertex(){
	    for(int i = 1; i<=V;i++){
	        for(int j = 1; j<=V;j++){
	            if(adjM[i][j] == 0) cout << ".  ";
	            else if (adjM[i][j] < 10) cout << adjM[i][j] << "  ";
	            else cout << adjM[i][j] << " ";
	        }
	        cout <<  endl;
	    }
	}
	
	void djikstra(int src){
		priority_queue<intPair, vector<intPair>, greater<intPair> >
        q;
		q.push(make_pair(1, src));
		int dist[V];
		for(int i = 1; i<=V; i++){
		    dist[i] = 100;
		}
		dist[src] = 1;
		
		while(!q.empty()){
			int u = q.top().second;
			q.pop();
			for(int i = 1; i <= V; i++){
				int v = i;
				int w = adjM[u][i];
				if(dist[v] > dist[u] + w && w != 0){
					dist[v] = dist[u] + w;
					q.push(make_pair(dist[v], v));
				}
			}
		}
		cout << "Vertex Distance from Source\n";
    for (int i = 0; i < V; ++i)
        cout << i << "\t" << dist[i] <<"\n";
	}
};

int main(){
	Graph g(20);
	g.addVertex("Rumah",0, 0, 1);
    g.addVertex("Masjid",0, 1, 2);
    g.addVertex("Patung Macan",0, 2, 4);
    g.addVertex("SD 3",0, 4, 7);
    g.addVertex("Minimarket 4",2, 3, 8);
    g.addVertex("Supermarket",2, 5, 6);
    g.addVertex("Pasar Subuh",2, 7, 20);
    g.addVertex("SD 2",2, 14, 16);
    g.addVertex("SPBU 2",2, 19, 28);
    g.addVertex("Kolam Renang",3, 6, 6);
    g.addVertex("Minimarket 3",4, 8, 2);
    g.addVertex("Minimarket 1",5, 9, 6);
    g.addVertex("SD 1",6, 12, 12);
    g.addVertex("SPBU 2",7, 19, 10);
    g.addVertex("Pasar",8, 17, 10);
    g.addVertex("SD 5",8, 18, 16);
    g.addVertex("Terminal",9, 10, 4);
    g.addVertex("Minimarket 2",10, 11, 2);
    g.addVertex("Pasar",10, 17, 4);
    g.addVertex("Hotel",11, 16, 8);
    g.addVertex("Rumah Sakit",11, 15, 10);
    g.addVertex("SPBU 1",12, 13, 40);
    g.addVertex("Patung Macan",14, 2, 16);
    g.addVertex("SD 2",15, 14, 12);
    g.addVertex("Pasar",17, 17, 1);
    g.addVertex("SPBU 2",19, 19, 1);
	g.showAllVertex();
	int src;
	cin >> src;
    g.djikstra(src);
}