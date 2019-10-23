#include<bits/stdc++.h>
using namespace std;

bool check(int *a,int i,int n)
{
    for(int i=0;i<=(n/2-1);i++)
    {
        if(a[i]<a[2*i+1])
            return false;
        if(2*i+2<n && a[i]<a[2*i+2])
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bool x=check(a,0,n);
    if(x)
        cout<<"YES";
    else
        cout<<"NO";
}
