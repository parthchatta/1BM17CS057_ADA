#include<iostream>
using namespace std;

void dfs(int a[5][5],int i,int j,int m,int n)
{
    if(i>=m || i<0 || j>=n || j<0)
        return;
    if(a[i][j]==1)
    {
        a[i][j]=0;
        dfs(a,i-1,j-1,m,n);
        dfs(a,i-1,j,m,n);
        dfs(a,i-1,j+1,m,n);
        dfs(a,i,j-1,m,n);
        dfs(a,i,j+1,m,n);
        dfs(a,i+1,j-1,m,n);
        dfs(a,i+1,j,m,n);
        dfs(a,i+1,j+1,m,n);
    }

}

int find_count(int a[5][5],int m,int n)
{
    int c=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==1)
            {
                dfs(a,i,j,m,n);
                c++;
            }

        }
    }
    return c;
}
int main()
{
    int m[5][5]={{1,0,1,0,1},
                 {1,1,0,0,0},
                 {0,0,1,0,1},
                 {1,0,0,0,1},
                 {1,0,1,0,1}};

    int island_count=find_count(m,5,5);
    cout<<island_count;
    return 0;
}
