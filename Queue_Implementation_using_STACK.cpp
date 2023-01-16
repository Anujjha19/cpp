#include <bits/stdc++.h>

using namespace std;

struct Queue
{
    stack<int> s1, s2;

    // Push elements in queue
    void Push(int data)
    {
        // Pop out all elements from the stack s1
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        // Insert the desired element in the stack s1
        cout << "The element pushed is " << data << endl;
        s1.push(data);

        // Pop out elements from the stack s2 and push them into the stack s1
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    // Pop the element from the Queue
    int Pop()
    {
        if (s1.empty())
        {
            cout << "Stack is empty";
            exit(0);
        }

        int val = s1.top();
        s1.pop();
        return val;
    }
    // Return the Topmost element from the Queue
    int Top()
    {
        if (s1.empty())
        {
            cout << "Stack is empty";
            exit(0);
        }
        return s1.top();
    }
    int size()
    {
        return s1.size();
    }
};
int main()
{
    Queue q;
    q.Push(3);
    q.Push(4);
    cout << "The element poped is " << q.Pop() << endl;
    q.Push(5);
    cout << "The top of the queue is " << q.Top() << endl;
    cout << "The size of the queue is " << q.size() << endl;
}
