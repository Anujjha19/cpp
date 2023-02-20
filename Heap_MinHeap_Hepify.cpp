#include <bits/stdc++.h>
using namespace std;


void minHeap(int arr[],  int n, int i)
{

    int smallest = i;
    int left = 2 * i +1 ;
    int right = 2 * i + 2;

    if (left < n && arr[smallest] > arr[left])
    {
        smallest = left;
    }
    if (right < n && arr[smallest] > arr[right])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        minHeap(arr, n, smallest);
    }
}

int main()
{

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for (int i = (n / 2); i > 0; i--)
    {
        minHeap(arr, n, i);
    }

    cout << "Printing Array After Heapify " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}