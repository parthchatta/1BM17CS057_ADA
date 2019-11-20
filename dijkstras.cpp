#include<bits/stdc++.h>
using namespace std;
# define v 9

int findmin(int visited[v],int dist[v])
{
    int minv=INT_MAX;
    int min_index;
    for(int i=0;i<v;i++)
    {
        if(!visited[i] && dist[i]<minv)
        {
            minv=dist[i];
            min_index=i;
        }
    }
    return min_index;
}

void dijkstras(int graph[v][v],int source)
{
    int visited[v]={0};
    int dist[v];
    for(int i=0;i<v;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[source]=0;
    for(int i=0;i<v-1;i++)
    {
        int vertex= findmin(visited,dist);
        //cout<<"vertex:"<<vertex<<endl;
        visited[vertex]=1;
        for(int j=0;j<v;j++)
        {
            //cout<<visited[j]<<" "<<j<<" "<<dist[j]<<" "<<dist[vertex]+graph[j][vertex]<<endl;
            if(visited[j] == 0 && (graph[vertex][j] != 0 ) && (dist[vertex] != INT_MAX) && (dist[j] > (dist[vertex]+graph[vertex][j])) )
            {
                dist[j]=dist[vertex]+graph[vertex][j];
                //cout<<j<<" "<<dist[j]<<", ";
            }
        }
        //cout<<endl;

    }
    cout<<"edge\t\tdistance\n";
    for(int i=0;i<v;i++)
    {
        cout<<"0 - "<<i<<"\t\t"<<dist[i]<<endl;
    }
}

int main()
{
    int graph[v][v] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    int source=0;
    dijkstras(graph,source);

}
