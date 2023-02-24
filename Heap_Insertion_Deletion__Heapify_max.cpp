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
        /*
        size =0;
        parent = i
        left Index = 2 * i + 1
        right Index = 2 * i + 2

         */
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

    void deletionInHeap()
    {

        if (size == 0)
        {
            cout << -1;
            return;
        }
        // Step 1 Put Last Elemnt into First

        arr[1] = arr[size];
        // Step 2 Remove Last Element
        size--;

        // Step 3 Take Root Node to its Correct Position
        int index = 1;
        while (index < size)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;
            if (leftIndex < size && arr[index] < arr[leftIndex])
            {
                swap(arr[index], arr[leftIndex]);
                index = leftIndex;
            }
            else if (rightIndex < size && arr[index] < arr[rightIndex])
            {
                swap(arr[index], arr[rightIndex]);
                index = rightIndex;
            }
            else
            {
                return;
            }
        }
    }
};

void Heapify(int arr[], int n, int i)
{
    /* 
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2; 
    */
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

int main()
{

    heap h;
    h.insertionInHeap(50);
    h.insertionInHeap(55);
    h.insertionInHeap(53);
    h.insertionInHeap(52);
    h.insertionInHeap(54);

    h.print();

    h.deletionInHeap();

    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

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

    return 0;
}