#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n2*log(n2))
// Auxiliary Space: O(n)

int kthLargestSum(vector<int> &arr, int N, int k)
{
    vector<int> sumStore;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;

        for (int j = i; j < N; j++)
        {
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }

    sort(sumStore.begin(), sumStore.end());

    return sumStore[sumStore.size() - k];
}

// TC - O ( n2 )
// SC - O ( K )
int getKthLargest_SpaceOptimized(vector<int> &arr, int k)
{
    //	Write your code here.
    priority_queue<int, vector<int>, greater<int>> mpq;
    int N = arr.size();
    int K = k;

    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = i; j < N; j++)
        {
            sum += arr[j];

            if (mpq.size() < K)
            {
                mpq.push(sum);
            }
            else
            {
                if (sum > mpq.top())
                {
                    mpq.pop();
                    mpq.push(sum);
                }
            }
        }
    }
    return mpq.top();
}

int main()
{
    int a[] = {20, -5, -1};
    int N = sizeof(a) / sizeof(a[0]);
    int K = 3;
    vector<int> inVec(a, a + N);

    cout << kthLargestSum(inVec, N, K);
    return 0;
}
