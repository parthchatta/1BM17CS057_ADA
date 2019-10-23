#include<bits/stdc++.h>
using namespace std;

struct MinHeapNode
{
    int element;
    int i;
    int j;
};


void heapify(MinHeapNode *harr,int i,int heap_size)
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int smallest = i;
    if (l < heap_size &&
        harr[l].element < harr[i].element)
        smallest = l;
    if (r < heap_size &&
        harr[r].element < harr[smallest].element)
        smallest = r;
    if (smallest != i)
    {
        swap(harr[i], harr[smallest]);
            heapify(harr,smallest,heap_size);
    }
}


void build(MinHeapNode a[], int heap_size)
{
    MinHeapNode *harr;
    harr = a;
    int i = (heap_size - 1)/2;
    while (i >= 0)
    {
        heapify(harr,i,heap_size);
        i--;
    }
}


void findSmallestRange(int arr[][5], int k)
{
    int N=5;
    int range = INT_MAX;
    int min = INT_MAX, max = INT_MIN;
    int start, end;
    MinHeapNode *harr = new MinHeapNode[k];
    for (int i = 0; i < k; i++)
    {
        harr[i].element = arr[i][0];
        harr[i].i = i;
        harr[i].j = 1;
        if (harr[i].element > max)
            max = harr[i].element;
    }
    build(harr, k);
    while (1)
    {
        MinHeapNode root = harr[0];
        min = harr[0].element;
        if (range > max - min + 1)
        {
            range = max - min + 1;
            start = min;
            end = max;
        }
        if (root.j < N)
        {
            root.element = arr[root.i][root.j];
            root.j += 1;
            if (root.element > max)
                max = root.element;
        }
        else
            break;

        harr[0] = root;
        heapify(harr,0,k);
        //hp.replaceMin(root);
    }

    cout << "The smallest range is " << "["
         << start << " " << end << "]" << endl;;
}


int main()
{
    int arr[][5] = {{4, 7, 9, 12, 15},
                    {0, 8, 10, 14, 20},
                    {6, 12, 16, 30, 50}};
    int k = sizeof(arr)/sizeof(arr[0]);

    findSmallestRange(arr, k);

    return 0;
}
