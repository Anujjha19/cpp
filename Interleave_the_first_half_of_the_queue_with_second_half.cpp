#include <bits/stdc++.h>
using namespace std;

// Function to interleave the queue
void interLeaveQueue(queue<int> &q)
{
    stack<int>s;
        int n = q.size();

    for (int i = 0; i < n / 2; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < n / 2; i++)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    for (int i = 0; i < n / 2; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }
    while (!s.empty())
    {
        int val = s.top();
        q.push(val);
        s.pop();
        int x = q.front();
        q.push(x);
        q.pop();
    }

}
// TC - O(N)
// SC - O(N)

/* void interLeaveQueue(queue<int> &q)
{
    int n = q.size();
    queue<int> newq;
    for (int i = 0; i < n / 2; i++)
    {
        int val = q.front();
        q.pop();
        newq.push(val);
    }
    while (!newq.empty())
    {
        int val = newq.front();
        q.push(val);
        newq.pop();
        int x = q.front();
        q.push(x);
        q.pop();
    }
}
// TC - O(N)
// SC - O(N)
 */
int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    interLeaveQueue(q);
    int length = q.size();
    for (int i = 0; i < length; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
