#include<iostream>
using namespace std;
int main()
{
    int n=5;
    //cin>>n;
    int a[n][n]={{0,2,999,1,8},
                  {6,0,3,2,999},
                  {999,999,0,4,999},
                  {999,999,2,0,3},
                  {3,999,999,999,0}
                };

    /*
    for(int i=0;i<n;i++)
    {
        for(int j=0j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    */


    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for( int j=0;j<n;j++)
            {
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
