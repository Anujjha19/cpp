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

void bubbleSortAraay(int arr[], int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return;
    }
    
    // 1 case solved - it will take largest element to an end
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
        // recursive call

   bubbleSortAraay(arr, n - 1);
}
int main()
{
    int data[] = {20, 12, 10, 15, 2};
    /* int data[] = {}; */
    int size = sizeof(data) / sizeof(data[0]);
    cout << "Array given is :" <<endl;   
    printArray(data, size);
    cout<< endl;
    bubbleSortAraay(data, size);
    cout << "Sorted array in Acsending Order:\n";
    printArray(data, size);

    return 0;
}