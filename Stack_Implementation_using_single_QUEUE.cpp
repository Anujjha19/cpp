#include <bits/stdc++.h>

using namespace std;

class Stack
{
    // queue<int> q1;
    // queue<int> q2;
    queue<int> sq;

public:
    /* //Using Multiple Queue
    void Push(int x)
    {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap( q1, q2);
    }
    int Top()
    {
        return q1.front();
    }
    int Pop()
    {
            q1.pop();
        return 0;
    }
    int Size()
    {
        return q1.size();
    } */

    void Push(int x)
    {
        sq.push(x);
        for (int i = 0; i < sq.size() - 1; i++)
        {
            sq.push(sq.front());
            sq.pop();
        }
    }
    int Top()
    {
        return sq.front();
    }
    int Pop()
    {
        int n = sq.front();
        sq.pop();
        return n;
    }
    int Size()
    {
        return sq.size();
    }
};

int main()
{
    Stack s;
    s.Push(3);
    s.Push(2);
    s.Push(4);
    s.Push(1);

    cout << "Top of the stack: " << s.Top() << endl;
    cout << "Size of the stack before removing element: " << s.Size() << endl;
    cout << "The deleted element is: " << s.Pop() << endl;
    cout << "Top of the stack after removing element: " << s.Top() << endl;
    cout << "Size of the stack after removing element: " << s.Size();
}
// Time Complexity: O(N)
// Space Complexity: O(N)