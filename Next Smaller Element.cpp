/*
    Time Complexity: O(N ^ 2)
    Space Complexity: O(1)

    Where N denotes the number of elements in the array.
*/
/* #include "bits/stdc++.h"
using namespace std;
\
void printNSE(int arr[], int n)
{
    int next, i, j;
    for (i = 0; i < n; i++)
    {
        next = -1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                next = arr[j];
                break;
            }
        }
        cout << arr[i] << " -- " << next << endl;
    }
}

// Driver Code
int main()
{
    int arr[]= {11, 13, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNSE(arr, n);
    return 0;
}*/

/* APPROACH 1
vector<int> nextSmallerElement(vector<int> & arr, int n)
{
    // Defining the vector to store next smaller elements for the array.
    vector<int> ans(n);

    // Iterating through all the array elements and finding next smaller element for each element.
    for (int i = 0; i < n; i++)
    {
        // Initializing the next smaller element as -1.
        ans[i] = -1;

        // Moving to the right of the element.
        for (int j = i + 1; j < n; j++)
        {
            // Checking for the next smaller element.
            if (arr[i] > arr[j])
            {
                ans[i] = arr[j];
                break;
            }
        }

    }

    // Returning the final vector after all the iterations.
    return ans;
}
// Time Complexity: O(N^2)     : The worst case occurs when all elements are sorted in increasing order.

// Auxiliary Space: O(1):  As constant extra space is used  */


// APPROACH 2


#include <stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Defining the stack and pushing -1 to it.
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    // Iterating through all the array elements from backwards.
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        // Removing all the elements greater than or equal to current element from the stack.
        while (s.top() >= curr)
        {
            s.pop();
        }
        // ans is stack ka top
        // Setting the next smaller element as the element at top of stack.
        ans[i] = s.top();
        // Pushing the current element into the stack.
        s.push(curr);
    }
    // Returning the final vector after all the iterations.

    return ans;
}

// Time Complexity: O(N)     : The worst case occurs when all elements are sorted in increasing order.

// Auxiliary Space: O(n):  As constant extra space is used