#include<bits/stdc++.h>
using namespace std;

class Graph {
    protected:
        int v;
        list<int> adj[100];

    public:
        Graph(int len) {
            v = len;
        }

        void addVertex(int u, int v){
            adj[u].push_back(v);
        }

        void showGraph(){
            for (int i = 0; i < v; i++)
            {
                list<int>::iterator it;
                cout << i << " ";
                for(it = adj[i].begin(); it != adj[i].end(); ++it){
                    cout << *it << " ";
                }
                cout << endl;
            }
        }

        void BFS(int start){
            cout << "===BFS===" << endl;
            bool visited[100];
            for (int i = 0; i < v; i++)
            {
                visited[i] = false;
            }
            
            queue<int> q;

            visited[start] = true;

            list<int>::iterator it;

            q.push(start);

            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                cout << "(V" << curr << ")" << endl;
                for (it = adj[curr].begin(); it != adj[curr].end(); it++)
                {
                    int index = *it;
                    if(!visited[index])
                    {
                        visited[index] = true;
                        q.push(index);
                    }
                }
            }
        }
};


int main(){
	
    Graph g(20);
	g.addVertex(0, 1);
    g.addVertex(0, 2);
    g.addVertex(0, 4);
    g.addVertex(2, 3);
    g.addVertex(2, 5);
    g.addVertex(2, 7);
    g.addVertex(2, 14);
    g.addVertex(2, 19);
    g.addVertex(3, 6);
    g.addVertex(4, 8);
    g.addVertex(5, 9);
    g.addVertex(6, 12);
    g.addVertex(7, 19);
    g.addVertex(8, 17);
    g.addVertex(8, 18);
    g.addVertex(9, 10);
    g.addVertex(10, 11);
    g.addVertex(10, 17);
    g.addVertex(11, 16);
    g.addVertex(11, 15);
    g.addVertex(12, 13);
    g.addVertex(14, 2);
    g.addVertex(15, 14);
    
    g.showGraph();

    g.BFS(0);
}