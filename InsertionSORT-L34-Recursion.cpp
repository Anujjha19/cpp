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

void insertionSort(int arr[], int idx, int size)
{
   //base case
        if(idx == size)
            return;

        int curr = arr[idx];
        int j = idx - 1;

        while(j >= 0){
            if(curr < arr[j]){ // found greater value than curr shift to right
                arr[j + 1] = arr[j--];
            }
            else // Smaller element found
                break;
        }
        arr[j + 1] = curr; //place curr element at correct place

        // one part Done recursion will do other work;
        insertionSort(arr , idx + 1 , size);
    }
int main()
{
    int data[] = {20, 12, 10, 15, 2};
    int size = sizeof(data) / sizeof(data[0]);
    printArray(data, size);

    insertionSort(data, 0,size);
    cout << "Sorted array in Acsending Order:\n";
    printArray(data, size);
}
