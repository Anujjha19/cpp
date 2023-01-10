/* //Brute Force

// TC - o(n^2)

#include <iostream>
using namespace std;

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int data[] = {3, 5, 6, 9, 1, 2, 7, 8};
    int n = 8;
    printArray(data, n);

    cout << endl;
    cout << "Inversion Count is";
    int invC = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (data[i] > data[j])
            {
                invC++;
            }
        }
    }
    cout << invC;

    return 0;
} */

#include <iostream>
using namespace std;

long long merge(int arr[], int l, int mid, int r)
{
    long long invC = 0;
    int n1 = mid - 1 + 1;
    int n2 = r - mid;
    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i] = a[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = b[mid - i + 1];
    }
    int i = 0;
    int j = 0;
    int k = 1;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = b[j];
            // a[i], a[i+1]... >b[j] . i<j invC=+
            invC += n1 - i;
            j++;
            k++;
        }
    }
    while(i<n1){
         arr[k] = a[i];
            i++;
            k++;
    }
    while(j<n2){
         arr[k] = b[j];
            i++;
            k++;
    }
    return invC;
}

long long mergeSort(int arr[], int l, int r)
{
    long long invC = 0;
    if (l <r)
    {
        int mid = (l + r) / 2;
        invC += mergeSort(arr, l, mid);
        invC += mergeSort(arr, mid + 1, r);
        invC += merge(arr, l, mid, r) ;
    }

    return invC;
}

int main()
{
    int n;
    cout << "size of arraay :";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    cout << mergeSort(arr, 0, n - 1);

    // return 0;
}