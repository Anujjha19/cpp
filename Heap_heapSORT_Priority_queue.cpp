#include <bits/stdc++.h>
using namespace std;

class heap
{

public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insertionInHeap(int val)
    {
        size = size + 1;
        int index = size;

        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
// O based indexing then left <= n
//  1 based ;eft < n

void Heapify(int arr[], int n, int i)
{

    /* int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2; */
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        Heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;

    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;
        Heapify(arr, size, 1);
    }
}

int main()
{

    heap h;
    h.insertionInHeap(50);
    h.insertionInHeap(55);
    h.insertionInHeap(53);
    h.insertionInHeap(52);
    h.insertionInHeap(54);

    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    // Creation a Hep
    for (int i = (n / 2); i > 0; i--)
    {
        Heapify(arr, n, i);
    }

    cout << "Printing Array After Heapify " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Heap sort
    heapSort(arr, n);
    cout << "Printing Array After HeapSort " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Max Heap
    cout << " Implementing Priority Queue " << endl;

    priority_queue<int> pq;
    pq.push(4);
    pq.push(8);
    pq.push(7);
    pq.push(1);
    cout << " Top Element Max : " << pq.top() << endl;
    pq.pop();
    cout << " Top Element Max : " << pq.top() << endl;
    cout << " Size of Heap : " << pq.size() << endl;

    if (pq.empty())
        cout << " Empty ";
    else
        cout << " Not Empty ";


    cout <<endl;    

    // Min Heap

    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(4);
    minHeap.push(8);
    minHeap.push(7);
    minHeap.push(1);
    cout << " Top Element Min : " << minHeap.top() << endl;
    minHeap.pop();
    cout << " Top Element Min : " << minHeap.top() << endl;
    cout << " Size of MinHeap : " << minHeap.size() << endl;

    if (minHeap.empty())
        cout << " Empty ";
    else
        cout << " Not Empty ";

    return 0;
}