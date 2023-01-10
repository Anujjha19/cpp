#include <bits/stdc++.h>

void solve(stack<int> &inputStack, int count, int size)
{
    
    if (inputStack.empty())
    {
        return;
    }
    if (count == size / 2)
    {
        inputStack.pop();
        return;
    }
    int num = inputStack.top();
    inputStack.pop();

    // Recursive Call
    solve(inputStack, count + 1, size);
    inputStack.push(num);
}
void deleteMiddle(stack<int> &inputStack, int N)
{

    int count = 0;
    solve(inputStack, count, N);
}