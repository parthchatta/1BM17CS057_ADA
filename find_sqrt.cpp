#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter number: ";
    cin>>n;
    int h=n,l=1;
    int mid,x;
    while(l<=h)
    {
        mid=(h+l)/2;

        if(mid*mid==n)
        {
            x=mid;
            break;
        }
        else if(mid*mid<n)
        {
            l=mid+1;
            x=mid;
        }
        else
        {
            h=mid-1;
        }
    }
    cout<<"the square root or floor(square root) is: "<<x;
    return 0;
}
