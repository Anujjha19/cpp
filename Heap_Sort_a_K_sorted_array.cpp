
#include <bits/stdc++.h>
using namespace std;

void sortK(int arr[], int n, int k, vector<int> &v)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++)
    {
        minHeap.push(arr[i]);
        if (minHeap.size() > k)
        {
            v.push_back(minHeap.top());
            minHeap.pop();
        }
    }
    while (!minHeap.empty())
    {
        v.push_back(minHeap.top());
        minHeap.pop();
    }
}

int main()
{
    int k = 3;
    int arr[] = {2, 6, 3, 12, 56, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v;
    sortK(arr, n, k, v);

    cout << "Following is sorted arrayn";

    for (auto it : v)
    {
        cout << it << " ";
    }
    return 0;
}
