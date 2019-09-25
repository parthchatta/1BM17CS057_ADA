#include<bits/stdc++.h>
using namespace std;

bool can_place(int grid[100][100],int row,int col,int n)
{
    for(int i=row-1;i>=0;i--)
    {
        if(grid[i][col]==1)
            return false;
    }
    for(int i=row-1,j=col-1;i>=0,j>=0;i--,j--)
    {
        if(grid[i][j]==1)
            return false;
    }
    for(int i=row-1,j=col+1;i>=0,j<n;i--,j++)
    {
        if(grid[i][j]==1)
            return false;
    }
    return true;
}

bool solve(int grid[100][100],int n,int row)
{

    if(row==n)
        return true;

    for(int i=0;i<n;i++)
    {
        if(can_place(grid,row,i,n))
        {
            //cout<<"<"<<row<<" "<<i<<">\n";
            grid[row][i]=1;
            if(solve(grid,n,row+1))
            {
                return true;
            }
            else
            {
                grid[row][i]=0;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    int grid[100][100]={0};
    //int **grid=new int*[n];
    //for(int i=0;i<n;i++)
    //{
        //grid[i]=new int[n]{0};
   // }

    bool q=solve(grid,n,0);
    if(q)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<grid[i][j]<<" ";
            cout<<endl;
        }
    }
    else
    {
        cout<<"no sloution.\n";
    }
    //for(int i=0;i<n;i++)
    //{
        //delete grid[i];
    //}
    //delete grid;
    return 0;

}
