#include<bits/stdc++.h>
using namespace std;

bool find_empty_position(int grid[][9],int &r,int &c)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(grid[i][j]==0)
            {
                r=i;c=j;
                return true;
            }
        }
    }
    return false;
}

bool can_place(int grid[9][9],int r,int c,int x)
{
    for(int i=0;i<9;i++)
    {
        if(grid[r][i]==x)
            return false;
    }
    for(int i=0;i<9;i++)
    {
        if(grid[i][c]==x)
            return false;
    }
    int rs=(r/3)*3;
    int cs=(c/3)*3;
    for(int i=rs;i<rs+3;i++)
    {
        for(int j=cs;j<cs+3;j++)
        {
            if(grid[i][j]==x)
                return false;
        }
    }
    return true;
}

bool solve(int grid[][9])
{
    int r,c;
    if(!find_empty_position(grid,r,c))
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
                cout<<grid[i][j]<<" ";
            cout<<"\n";
        }
        return true;
    }
    else
    {
        for(int i=1;i<=9;i++)
        {
            if(can_place(grid,r,c,i))
            {
               grid[r][c]=i;
               if(solve(grid))
                    return true;
                else
                    grid[r][c]=0;
            }
        }
        return false;
    }
}
int main()
{
    int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    bool a=solve(grid);
    if(!a)
        cout<<"cannot solve sudoku\n";
    return 0;
}
