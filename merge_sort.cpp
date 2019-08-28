#include<iostream>
using namespace std;

void merge_array(int a[],int l,int m,int h)
{
    int *t=new int[h-l+1];
    int i=l,j=m+1,k=0;
    while(i<=m && j<=h)
    {
        if(a[i]<a[j])
        {
            t[k]=a[i];
            k++;i++;
        }
        else
        {
           t[k]=a[j];
           k++;j++;
        }

    }
    while(i<=m)
    {
        t[k]=a[i];
        k++;i++;
    }

    while(j<=h)
    {
        t[k]=a[j];
        k++;j++;
    }


    for(i=l,k=0;i<=h;i++,k++)
    {
        a[i]=t[k];
    }
    delete []t;
}

void merge_sort(int a[],int l,int h)
{
    if(l<h)
    {
        int m=(l+h)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,h);
        merge_array(a,l,m,h);

    }
}

int main()
{
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    merge_sort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    delete []a;
}
