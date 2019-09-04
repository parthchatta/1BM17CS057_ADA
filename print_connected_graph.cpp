#include<bits/stdc++.h>
using namespace std;
class graph{
    int v;
    list<int> *adj;
    public:
    graph(int v){
        this->v=v;
        adj=new list<int>[v];
    }

    void add_edge(int m,int n){
        adj[m].push_back(n);
    }

    void DFS()
    {
        cout<<"h";
        stack<int> s;
        vector<bool> visited(v,false);
        //cout<<start;
        for(int i=1;i<=10;i++)
        {
            if(visited[i]==false)
            {
            s.push(i);
            }

            while(!s.empty())
            {
                int vertex=s.top();
                //cout<<vertex;
                s.pop();
                if(visited[vertex]==false){
                    cout<<vertex<<" ";
                    visited[vertex]=true;
                }
                for(auto i=adj[vertex].begin();i!=adj[vertex].end();++i){
                    if(visited[*i]==false){
                        s.push(*i);
                    }
                i++;
                }

            }

        }
}
};

int main()
{
    graph g(5);
    g.add_edge(1,2);
    g.add_edge(1,3);
    g.add_edge(2,3);
    g.add_edge(3,4);
   // g.add_edge(8,9);
    //g.add_edge(5,6);
    //g.add_edge(6,7);
    cout<<"start\n";
    g.DFS();
    cout<<"\nend";
    return 0;
}
