#include<iostream>
#include<fstream>
using namespace  std;
int find_lower(int a[],int n,int x)
{
    int l=0,h=n-1;
    int mid,ans;
    while(l<=h)
    {
        mid=(h+l)/2;
        if(a[mid]==x)
        {
            ans=mid;
            h=mid-1;
        }
        else if(a[mid]>x)
        {
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return ans;
}
int find_upper(int a[],int n,int x)
{
    int l=0,h=n-1;
    int mid,ans;
    while(l<=h)
    {
        mid=(h+l)/2;
         if(a[mid]==x)
        {
            ans=mid;
            l=mid+1;
        }
        else if(a[mid]<x)
        {

            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }
    return ans;

}

int main()
{
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int x;
    cin>>x;
    int lower_index=find_lower(a,n,x);
    int upper_index=find_upper(a,n,x);
    int c=upper_index-lower_index+1;
    cout<<lower_index<<" "<<upper_index<<" "<<c<<endl;
    return 0;
}
