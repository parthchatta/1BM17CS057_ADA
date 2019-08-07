#include<iostream>
using namespace std;

class max_arr
{
	int n;
	int *arr;
	public:
	max_arr(int n)
	{
		this->n=n;
		arr=new int[this->n];
	}
	void insert()
	{
		cout<<"enter array elements:\n";
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
	}
	int max()
	{
		int max=arr[0];
		for(int i=1;i<n;i++)
		{
			if(arr[i]>max){max=arr[i];}
		}
		return max;
	}
};
int main()
{
	int n;
	cout<<"enter no. of array elements: ";
	cin>>n;
	max_arr o(n);
	o.insert();
	int m=o.max();
	cout<<"max number is:"<<m<<endl;
	return 0;
}
