#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool visited[])
    {
        visited[v] = true;
        cout << v << " ";
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
    }
    public:
    Graph(int V)
    {
        this->V=V;
        adj=new list<int>[V];
    }
    void addEdge(int v,int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    void connectedComponents()
    {
        bool *visited = new bool[V];
        for(int v = 0; v < V; v++)
        visited[v] = false;
        for (int v=0; v<V; v++)
        {
            if (visited[v] == false)
            {
            DFSUtil(v, visited);
            cout << "\n";
            }
        }
    }

};

int main()
{

    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    cout << "connected components are: \n";
    g.connectedComponents();
    return 0;
}
