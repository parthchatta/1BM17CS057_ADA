#include<iostream>
using namespace std;
class find_arr
{
	int n;
	int *arr;
	public:
	find_arr(int x)
	{
		n=x;
		arr=new int[n];	
	}
	~find_arr()
	{
		delete arr;	
	}
	void insert()
	{
		cout<<"enter array elements:\n";
		for(int i=0;i<n;i++)
		{cin>>arr[i];}	
	}
	bool find(int x)
	{
		int l=0,r=n-1;
		int mid;
		while(r>=l)
		{
			mid=l+(r-l)/2;
			if(arr[mid]==x)
			{return true;}
			else if(arr[mid]<x)
				l=mid+1;
			else
				r=mid-1;
		}
		return false;	
	}

};
int main()
{
	int t;
	cout<<"enter no. of test cases: ";
	cin>>t;
	while(t--)
	{	
		int n;
		cout<<"enter no. of array elements: ";
		cin>>n;
		find_arr o(n);
		o.insert();
		int x;
		cout<<"enter no. to be searched: ";
		cin>>x;
		bool q=o.find(x);
		if(q)
		{cout<<"1\n";}
		else
		{cout<<"-1\n";}		
			
	}
	return 0;
}
