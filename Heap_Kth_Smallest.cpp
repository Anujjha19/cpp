// C++ program to find K'th smallest element
#include <bits/stdc++.h>
using namespace std;

// O( nlog n)
int kthSmallestBF(int arr[], int N, int K)
{
    sort(arr, arr + N);

    return arr[K - 1];
}

// O(n log K)
int kthSmallest(int arr[], int n, int k)
{
    priority_queue<int> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    /*
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < n ; i++)
    {
        if (arr[i] > pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
     */

    return pq.top();
}
int kthLargesgt(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        if (arr[i] > pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}
int PrintFormkthLargesgt(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);

        if (pq.size() > k)
            pq.pop();
    }

    // return pq.top();

    while (pq.size() != 0)
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}

int main()
{
    int arr[] = {12, 3, 5, 7, 19};
    int N = sizeof(arr) / sizeof(arr[0]), K = 4;

    // Function call
    cout << "K'th smallest element is "
         << kthSmallest(arr, N, K);
    cout << endl;
    cout << "K'th Largest element is "
         << kthLargesgt(arr, N, K);
    return 0;
}
