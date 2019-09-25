#include<bits/stdc++.h>
using namespace std;

bool findmax(int out[],int tasks,int &t)
{

    for(int i=0;i<tasks;i++)
    {
        if(out[i]==0)
        {
            t=i;
            return true;
        }

    }
    return false;
}

int main()
{
    int tasks;
    cout<<"enter number of tasks: ";
    cin>>tasks;
    int dep[tasks][tasks]={0};
    cout<<"enter number of dependant task pairs: ";
    int pairs;
    cin>>pairs;
    while(pairs)
    {
        int t1,t2;
        cin >> t1 >> t2;
        dep[t1][t2]=1;
        pairs--;
    }
    int outdegree[tasks]={0};
    for(int i=0;i<tasks;i++)
    {
       for(int j=0;j<tasks;j++)
        {
            if(dep[i][j]==1)
                outdegree[i]+=1;
        }
    }
    int t;
    while(findmax(outdegree,tasks,t))
    {
        cout<<t<<" ";
        outdegree[t]=-1;
        for(int i=0;i<tasks;i++)
        {
            if(dep[i][t]==1)
            {
                dep[i][t]=0;
                outdegree[i]--;
            }
        }
    }

    return 0;
}

