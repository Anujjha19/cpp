
/* //Approach 1: Using Stack

queue<int> rev(queue<int> q)
{

stack <int>s;
while(!q.empty()){
    int element = q.front();
    q.pop();
    s.push(element);
}
while(!s.empty()){
    int element = s.top();
    s.pop();
    q.push(element);
}
return q;

} */

// Approach 2: Using Recursion
#include <bits/stdc++.h>
#include <queue>
using namespace std;
void printQueue(queue<int> Queue)
{
    while (!Queue.empty())
    {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}

/* Main Part */
void fun(queue<int> &Queue)
{
    if (Queue.empty())
        return;
    int num = Queue.front();
    Queue.pop();
    fun(Queue);
    Queue.push(num);
}
void rev(queue<int> &Queue)
{
    fun(Queue);
}
/* Ends */

int main()
{
    queue<int> Queue;
    Queue.push(56);
    Queue.push(27);
    Queue.push(30);
    Queue.push(45);
    Queue.push(85);
    Queue.push(92);
    Queue.push(58);
    Queue.push(80);
    Queue.push(90);
    Queue.push(100);
    printQueue(Queue);
    cout<<endl;
    rev(Queue);
    printQueue(Queue);
}