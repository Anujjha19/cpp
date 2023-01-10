#include<iostream>
using namespace std;

void merge(int *arr, int s, int e) {

    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

   // mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted arrays     
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }   

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2 ) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;

}

void mergeSort(int *arr, int s, int e) {

    //base case
    if(s >= e) {
        return;
    }
    
    int mid = (s+e)/2;

    //left part sort karna h 
    mergeSort(arr, s, mid);
    
    //right part sort karna h 
    mergeSort(arr, mid+1, e);

    //merge
    merge(arr, s, e);

}

int main() {

    int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15;

    mergeSort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}
/* #include <iostream>
#include <vector>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1; // size of left part
    int len2 = e - mid;     // size of right part

    // creating array for both part
    int *first = new int[len1];
    int *second = new int[len2];

    // Copy values
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] == arr[mainArrayIndex++];
    }
    // merge 2 sorted arrays

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }
    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }
    delete[] first;
    delete[] second;
}

void mergeSort(int *arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    // Left part sort
    mergeSort(arr, s, mid);

    // right part sort
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}

void print(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[5] = {1, 3, 5, 7, 9};
    int n = 5;

    print(arr, 5);

    mergeSort(arr, 0, n - 1);
} */

/* #include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int l, int r)
{
    int mid = l + (r - l) / 2;

    int len1 = mid - l + 1; // size of left part
    int len2 = r - mid;     // size of right part

    // creating array for both part
    int a[len1];
    int b[len2]; // temp array

    // Copy values
    // int mainArrayIndex = l;
    for (int i = 0; i < len1; i++)
    {
        a[i] = arr[l + i];
    }
    // mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        b[i] == arr[mid + 1 + i];
    }
    // merge 2 sorted arrays

    int i = 0;
    int j = 0;
    int k = l;
    while ((i < len1) && (j < len2))
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < len1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < len2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    // base case
    if (l < r)
    

    int mid = l + (r - l) / 2;
    // Left part sort
    mergeSort(arr, l, mid);

    // right part sort
    mergeSort(arr, mid + 1, r);

    // Merging both array
    merge(arr, l,mid );
}

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    int n = 5;
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
} */