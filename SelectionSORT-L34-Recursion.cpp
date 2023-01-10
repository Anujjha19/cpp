#include <iostream>
using namespace std;

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void selectionSort(int array[], int n, int i)
{
    // base case
    if (i == n)
    {
        return;
    }
    int minIndex = i;
    for (int j = i + 1; j < n; j++)
    {
        if (array[minIndex] >+array[j])
        {
            minIndex = j;
        }
    }
    swap(array[i], array[minIndex]);

    selectionSort(array, n,i + 1 );
    
}

int main()
{
    int data[] = {20, 12, 10, 15, 2};
    int size = sizeof(data) / sizeof(data[0]);
    printArray(data, size);

    cout << endl;
    cout << "Sorted array in Acsending Order: ";
    
    selectionSort(data , 5,0);
     printArray(data, size);
   
   return 0;
}