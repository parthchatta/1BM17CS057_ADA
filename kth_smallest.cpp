#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int find(int a[],int n,int k)
{
	for(int i=0;i<k;i++)
	{
		int x=i; 
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[x])
			{
				x=j;
			}
		}
		swap(&a[i],&a[x]);
	}
	return a[k-1];
}


int main()
{
	freopen("input.txt","r",stdin);
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int kth_smallest=find(a,n,k);
	cout<<kth_smallest<<endl;
		
}
