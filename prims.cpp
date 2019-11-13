#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int cost[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>cost[i][j];
        }
    }
    int ne=0;
    int mincost=0;
    int elec[n];
    for(int i=0;i<n;i++)
    {
            elec[i]=0;
    }
    elec[0]=1;
    while(ne!=n-1)
    {
        int cmin=INT_MAX;
        int u=0,v=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(elec[i]==1)
                {
                    if(cost[i][j]<cmin)
                    {
                        cmin=cost[i][j];
                        u=i;
                        v=j;
                    }

                }
            }
        }
        if(elec[v]!=1)
        {
            cout<<"("<<u<<","<<v<<") --> "<<cmin<<endl;
            elec[v]=1;
            ne=ne+1;
            mincost=mincost+cmin;
        }
        cost[u][v]=INT_MAX;
        cost[v][u]=INT_MAX;
    }
    cout<<"mincost: "<<mincost<<endl;
}
