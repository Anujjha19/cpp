/*

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{

    deque<long long int> dq;
    vector<long long> ans;

    // Process First WIndow of K size

    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }

    // Stored ans of first K size
    if (dq.size() > 0)
    {
        ans.push_back(A[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }
    // Process of remaining window
    for (int i = K; i < N; i++)
    {
        if (!dq.empty() && i - dq.front() >= K)
        {
            dq.pop_front();
        }
        // addition
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
        // ans store
        if (dq.size() > 0)
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
} */

#include <iostream>
#include <vector>
using namespace std;
#include <deque>
typedef long long ll;
vector<ll> printFirstNegativeInteger(ll A[], ll N, ll k)
{
    deque<ll> dll; // You can use queue, dequeue etc as well
    vector<ll> result;
    int i = 0, j = 0;

    while (j < N)
    {
        if (A[j] < 0)
            dll.push_back(A[j]);

        if (j - i + 1 == k)
        {
            ll neg = dll.empty() ? 0 : dll.front();
            result.push_back(neg);
            if (A[i] < 0 && !dll.empty())
            {
                dll.pop_front();
            }
            i++;
        }
        j++;
    }
    return result;
}

// Time Complexity: O(n) 

// Auxiliary Space: O(k)

/* 
#include <iostream>
using namespace std;

void printFirstNegativeInteger(int arr[], int k, int n)
{
    int firstNegativeIndex = 0;
    int firstNegativeElement;

    for (int i = k - 1; i < n; i++)
    {

        // skip out of window and positive elements
        while ((firstNegativeIndex < i) && (firstNegativeIndex <= i - k || arr[firstNegativeIndex] >= 0))
        {
            firstNegativeIndex++;
        }

        // check if a negative element is found, otherwise
        // use 0
        if (arr[firstNegativeIndex] < 0)
        {
            firstNegativeElement = arr[firstNegativeIndex];
        }
        else
        {
            firstNegativeElement = 0;
        }
        cout << firstNegativeElement << " ";
    }
}

// Driver code
int main()
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printFirstNegativeInteger(arr, k, n);
} 
Time Complexity: O(n) 

Auxiliary Space: O(1)
*/