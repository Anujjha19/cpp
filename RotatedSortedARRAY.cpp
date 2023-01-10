/* C++ Program to search an element
in a sorted and pivoted array*/
#include <bits/stdc++.h>
using namespace std;

/* Standard Binary Search function*/
int binarySearch(int arr[], int low,
				int high, int key)
{
	if (high < low)
		return -1;

	int mid = (low + high) / 2; /*low + (high - low)/2;*/
	if (key == arr[mid])
		return mid;

	if (key > arr[mid])
		return binarySearch(arr, (mid + 1), high, key);

	// else
	return binarySearch(arr, low, (mid - 1), key);
}

/* Function to get pivot. For array 3, 4, 5, 6, 1, 2
it returns 3 (index of 6) */
int findPivot(int arr[], int low, int high)
{
	// base cases
	if (high < low)
		return -1;
	if (high == low)
		return low;

	int mid = (low + high) / 2; /*low + (high - low)/2;*/
	if (mid < high && arr[mid] > arr[mid + 1])
		return mid;

	if (mid > low && arr[mid] < arr[mid - 1])
		return (mid - 1);

	if (arr[low] >= arr[mid])
		return findPivot(arr, low, mid - 1);

	return findPivot(arr, mid + 1, high);
}

/* Searches an element key in a pivoted
sorted array arr[] of size n */
int pivotedBinarySearch(int arr[], int n, int key)
{
	int pivot = findPivot(arr, 0, n - 1);

	// If we didn't find a pivot,
	// then array is not rotated at all
	if (pivot == -1)
		return binarySearch(arr, 0, n - 1, key);

	// If we found a pivot, then first compare with pivot
	// and then search in two subarrays around pivot
	if (arr[pivot] == key)
		return pivot;

	if (arr[0] <= key)
		return binarySearch(arr, 0, pivot - 1, key);

	return binarySearch(arr, pivot + 1, n - 1, key);
}

/* Driver program to check above functions */
int main()
{
	// Let us search 3 in below array
	int arr1[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
	int n = sizeof(arr1) / sizeof(arr1[0]);
	int key = 3;

	// Function calling
	cout << "Index of the element is : "
		<< pivotedBinarySearch(arr1, n, key);

	return 0;
}

/* #include<vector>
using namespace std;

int getPivot(vector<int>& arr, int n) {

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {

        if(arr[mid] >= arr[0])
        {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int binarySearch(vector<int>& arr, int s, int e, int key) {

    int start = s;
    int end = e;

    int mid = start + (end-start)/2;

    while(start <= end) {

        if(arr[mid] == key) {
            return mid;
        }

        //go to right wala part
        if(key > arr[mid]) {
            start = mid + 1;
        }
        else{ //key < arr[mid]
            end = mid - 1;
        }

        mid = start + (end-start)/2;
    }
    
    return -1;
}



int findPosition(vector<int>& arr, int n, int k)
{
    int pivot = getPivot(arr, n);
    if( k >= arr[pivot] && k <= arr[n-1])
    {//BS on second line
        return binarySearch(arr, pivot, n-1, k);
    }
    else
    {//BS on first line
        return binarySearch(arr, 0, pivot - 1, k);
    }
    
} */
