#include <iostream>
#include <list>
#include <queue>
#include <string.h>
using namespace std;
typedef pair<int,int> intPair;

class Graph{
	int V;
	list<pair<int,int>> adj[21];
	string places[21];
	public:
	Graph(int v){
	    V = v;
	}
	
	void addVertex(string str, int u, int v, int w){
	    adj[u].push_back(make_pair(v, w));
	    places[v] = str;
	}
	
	void showAllVertex(){
	    for(int i = 0; i<V;i++){
	    	cout << i << " :";
	        for(auto const &j: adj[i]){
	            cout << " " << j.first << " ";
	        }
	        cout << endl;
	    }
	}
	
	void djikstra(int start){
		priority_queue<intPair, vector<intPair>, greater<intPair> >
        q;
		q.push(make_pair(1, start));
		int end[V];
		for(int i = 0; i<V; i++){
		    end[i] = 100;
		}
		end[start] = 1;
		
		while(!q.empty()){
			int u = q.top().second;
			q.pop();
			
			list<pair<int,int>> :: iterator i;
			for(i = adj[u].begin(); i != adj[u].end(); i++){
				int v = (*i).first;
				int w = (*i).second;
				if(end[v] > end[u] + w){
					end[v] = end[u] + w;
					q.push(make_pair(end[v], v));
				}
			}
		}
        cout << "Vertex distance from Source\n";
   		for (int i = 0; i < V; ++i)
        cout << i << "\t" << end[i] <<"\n";
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
	int start;
	cout << "insert start : ";
	cin >> start;
    g.djikstra(start);
}