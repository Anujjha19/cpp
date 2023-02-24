#include <bits/stdc++.h>

using namespace std;

int minCost(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    int sum = 0;
    int cost_minimum = 0;
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        sum = a + b;
        cost_minimum += sum;

        pq.push(sum);
    }
    return cost_minimum;
}

// Driver program to test above function
int main()
{
    int len[] = {4, 3, 2, 6};
    int size = sizeof(len) / sizeof(len[0]);
    cout << "Total cost for connecting ropes is "
         << minCost(len, size);
    return 0;
}
