#include<bits/stdc++.h>
using namespace std;
int bs(int a[],int n)
{
	int l=0,h=n-1;
	while(l<=h)
	{
		int mid=(h+l)/2;
		cout<<"<"<<mid<<">\n";
		if(a[mid]>a[(mid+1)%n] && a[mid]>a[(mid-1)%n] )
		{
			return mid;
		}
		else
		{
			l=(mid+1)%n;
			if(l==0)
			{
				h=(mid-1)%n;
			}
		}
		
	}
	return 0;
	 
}
int search(int a[],int n,int k)
{
	int index=-1;
	int l=0,h=n-1;
	while(l<=h)
	{
		int mid=(h+l)/2;
		if(a[mid]==k)
		{
			return mid;
		}
		else if(a[mid]<k)
		{
			l=mid+1;
		}
		else
		{
			h=mid-1;
		}
		
	}
	return index;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int p=bs(a,n);
		int index=search(a,p+1,k);
		int index2=search(a+p+1,n-p-1,k);
		if(index==-1)
		{
			cout<<index2<<"\n";
		}
		else
		{
			cout<<index<<"\n";
		}
	}
	return 0;
}
