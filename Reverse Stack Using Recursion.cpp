/*
Stack top ko side mai rakho,
use recursion to reverse remaining stack
while coming back - call InsertAtBottom for stack Top

//T.C = O(n2)
//S.C = O(n)
 */
void insertAtBottom(stack<int> &s, int element)
{
    // basecase
    if (s.empty())
    {
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();

    // recursive call
    insertAtBottom(s, element);

    s.push(num);
}

void reverseStack(stack<int> &stack)
{
    // base case
    if (stack.empty())
    {
        return;
    }

    int num = stack.top();
    stack.pop();

    // recursive call
    reverseStack(stack);

    insertAtBottom(stack, num);
}

/*
class Solution{
public:
    stack<int> Reverse(stack<int>st){

        stack<int>s1;

        reverse(st,s1);

        return s1;

    }

    void reverse(stack<int>st,stack<int>&s1)

    {

        if(st.empty())

        return;

        int a=st.top();

        st.pop();

        s1.push(a);

        reverse(st,s1);

    }
}; */

#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }

    int top = st.top();
    st.pop();
    insertAtBottom(st, ele);
    st.push(top);
}
void reverse(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int elemnt = st.top();
    st.pop();

    reverse(st);
    insertAtBottom(st, elemnt);
}

int main()
{

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverse(st);
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
        cout << endl;
    }

    return 0;
}
/* isn't is O(n^2) time complexity (n times reverse fun * n times insert at bottom fun) in worst cases...
and also the space complexity is O(n^2) (as recursion also consume memory, n^2 because another recursion call is taking place of insert fun) which was O(n) in iterative method with O(n) time complexity... correct me if i m wrong... */