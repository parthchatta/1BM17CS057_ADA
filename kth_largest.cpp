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
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j],&a[j+1]);
			}
		}
		
	}
	cout<<"<";
	for(int i=0;i<n;i++)
	{cout<<a[i]<<" ";}
	cout<<">\n";
	return a[n-k];
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
	int kth_largest=find(a,n,k);
	
	
	cout<<kth_largest<<endl;
		
}
