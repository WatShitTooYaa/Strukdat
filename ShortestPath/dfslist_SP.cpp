#include <iostream>
#include <list>
#include <iterator>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
using namespace std;

class Graph {
    protected:
        int v;
        vector<string> place;
        vector<list<int>> adj;
        map<pair<int,int>, int> weight;
        vector<int> dfsResult;
        int dfsWeight;
        vector<int> dijkstraRes;
        
    public:
        Graph(int len) {
            v = len;
            place.assign(v+1, "");
            list<int> l;
            adj.assign(v+1, l);
            dfsResult.assign(v+1, 0);
            vector<int> vec (v+1, 0);
        }
        
        void addVertex(string i, int u, int v, int w){
            adj[u].push_back(v);
            weight.insert({make_pair(u,v), w});
            place[v] = i;
        }

        void showGraph(){
            for (int i = 0; i < v; i++)
            {
                list<int>::iterator it;
                cout << i << " => ";
                for (it = adj[i].begin(); it != adj[i].end(); it++)
                {
                    cout << *it << "(" << weight[make_pair(i, *it)] << ") ";
                }
                cout << endl;
            }
        }

        void DFS(int start, int end){
            cout << endl;
            cout << "Shortest path using DFS" << endl;
            dfsWeight = INT_MAX;
            vector<int> path;
            vector<bool> visited (v+1, false);
            solveDFS(start, end, path, visited, 0 );
            
            for (int i = 0; i < dfsResult.size(); i++)
            {
                cout << dfsResult[i] << " ";
            }

            cout << endl << "Weight = " << dfsWeight << endl;
        }

        void solveDFS(int start, int end, vector<int> path, vector<bool> visited, int currWeight){
            if(start == end) {
                path.push_back(end);
                if(currWeight < dfsWeight ) {
                    dfsWeight = currWeight;
                    dfsResult = path;
                }
                cout << currWeight << " ";
                for (int i = 0; i < path.size(); i++)
                {
                    cout <<  path[i] << " ";
                }
                cout << endl;
            }
            visited[start] = true;
            path.push_back(start);
            list<int>::iterator it;
            for ( it = adj[start].begin(); it != adj[start].end(); it++)
            {
                if(!visited[*it]){
                    int wtemp = currWeight;
                    wtemp += weight[make_pair(start, *it)];
                    solveDFS(*it, end, path, visited, wtemp);
                }
            }
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
    g.showGraph();
    int start, end;
    cin >> start >> end;
    g.DFS(start, end);

    
}