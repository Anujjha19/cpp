/* #include <iostream>
using namespace std;

// Find the previous smaller element for every element in an array
void findPrevSmaller(int arr[], int n)
{
	// do for each element
	for (int i = 0; i < n; i++)
	{
		// keep track of the previous smaller element for element `arr[i]`
		int prev = -1;

		// process elements on the left of the element `arr[i]`
		for (int j = i - 1; j >= 0; j--)
		{
			// break the inner loop at the first smaller element on the
			// left of the element `arr[i]`
			if (arr[j] < arr[i])
			{
				prev = arr[j];
				break;
			}
		}

		cout << prev;
	}
}
Time Complexity: O(N^2)     : The worst case occurs when all elements are sorted in increasing order.

Auxiliary Space: O(1):  As constant extra space is used 

int main()
{
	int arr[] = { 2, 5, 3, 7, 8, 1, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);

	findPrevSmaller(arr, n);

	return 0;
} */

#include <iostream>
#include <stack>
using namespace std;
 
// Find the previous smaller element for every element in an array
void findPrevSmaller(int arr[], int n)
{
    // create an empty stack
    stack<int> s;
 
    // do for each element
    for (int i = 0; i < n; i++)
    {
        // loop till stack is empty
        while (!s.empty())
        {
            // If the stack's top element is less than the current element,
            // it is the previous smaller element
            if (s.top() < arr[i])
            {
                cout << s.top() << ' ';
                break;
            }
            // remove the stack's top element is less if it is greater or equal
            // to the current element
            else {
                s.pop();
            }
        }
 
        // If the stack becomes empty, all elements to the left
        // of the current element are greater
        if (s.empty()) {
            cout << -1 << ' ';
        }
 
        // push current element into the stack
        s.push(arr[i]);
    }
}
 
int main()
{
    int arr[] = { 2, 5, 3, 7, 8, 1, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    findPrevSmaller(arr, n);
 
    return 0;
}

// Time Complexity: O(N)     : The worst case occurs when all elements are sorted in increasing order.

// Auxiliary Space: O(n):  As constant extra space is used