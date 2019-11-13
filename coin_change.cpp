#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int k;
    cin>>k;
    int c[k+1];
    for(int i=0;i<=k;i++)
    {
        if(i==0)
        {
            c[i]=0;
        }
        else
        {
            int j=0;
            int m=INT_MAX;
            while(j<n && a[j]<=i)
            {
                m=min(m,1+c[i-a[j]]);
                j++;
            }
            c[i]=m;
        }
    }
    cout<<"min change required: "<<c[k];
}
