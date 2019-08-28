#include<bits/stdc++.h>
using namespace std;

int bubble_sort(int a[],int n)
{
    int c=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            c++;
            //if(a[j]>a[j+1])
            //  swap(&a[j],&a[j+1]);
        }
    }
    return c;
}

int selection_sort(int a[],int n)
{
    int c=0;
    for(int i=0;i<n-1;i++)
    {
        int k=i;
        for(int j=i+1;j<n;j++)
        {
            c++;
            //if(a[j]<a[k])
            //    k=j;
        }
        //swap(&a[i],&a[k])
    }
    return c;
}

int merge_array(int a[],int l,int m,int h)
{
    int *t=new int[h-l+1];
    int i=l,j=m+1,k=0;
    int c=0;
    while(i<=m && j<=h)
    {
        c++;
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
    return c;
}

int  merge_sort(int a[],int l,int h)
{

    if(l<h)
    {
        int m=(l+h)/2;
        int c1=merge_sort(a,l,m);
        int c2=merge_sort(a,m+1,h);
        int c3=merge_array(a,l,m,h);
        int c=c1+c2+c3;
        return c;
    }
    return 0;

}




int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int count1=selection_sort(a,n);
    int count2=bubble_sort(a,n);
    int count3=merge_sort(a,0,n-1);
    cout<<"\nbubble sort comparisons: "<<count1<<"\n selection sort comparisons: "<<count2<<" \n merge sort comparisons: "<<count3;
    return 0;

}
