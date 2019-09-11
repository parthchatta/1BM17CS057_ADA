#include<bits/stdc++.h>
using namespace std;

void bfs(int adj[][9],int visited[],queue<int> &q,int start)
{

    if( visited[start]!=1)
    {

        q.push(start);
        while(q.size()!=0)
        {
            int n=q.front();
            q.pop();
            if(visited[n]==0)
            {
                cout<<n<<" ";
                visited[n]=1;
            }

            for(int i=0;i<9;i++)
            {
                if(adj[n][i]==1)
                {
                    if(visited[i]==0)
                    {
                        q.push(i);
                        //cout<<"<"<<i<<">";
                    }

                }
            }
        }
    }

}

int  main()
{
    int adj[9][9]={ {0,1,1,1,0,0,0,0,0},
                    {1,0,0,0,1,0,0,0,0},
                    {1,0,0,0,0,0,0,1,0},
                    {1,0,0,0,1,0,0,1,0},
                    {0,1,0,1,0,1,1,0,0},
                    {0,0,0,0,1,0,0,0,0},
                    {0,0,0,0,1,0,0,0,0},
                    {0,0,1,1,0,0,0,0,1},
                    {0,0,0,0,0,0,0,1,0},
                    };

       /*int adj[6][6]={{0,1,1,0,0,0},
                      {1,0,0,1,0,0},
                      {1,0,0,1,0,0},
                      {0,1,1,0,1,1},
                      {0,0,0,1,0,0},
                      {0,0,0,1,0,0}
                     };*/
    int v=0;
    int visited[9]={0};
    queue<int> q;
    bfs(adj,visited,q,v);
    return 0;
}
