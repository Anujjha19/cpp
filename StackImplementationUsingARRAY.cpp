#include <iostream>
#include <stack>
using namespace std;

class Stack
{

    // properties
public:
    int *arr;
    int top;
    int size;

    // behaviour
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << " Stack OverFlow " << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << " Stack Underflow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << " Stack Is Empty " << endl;
            return -1;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// Complexity of Push = O(1)
// Complexity of Pop = O(1)
// Complexity of Peek = O(1)
// Complexity of isEmpty = O(1)

int main()
{
    Stack st(5);

    st.push(22);
    st.push(21);
    st.push(20);

    cout << st.peek() << endl; // 20

    st.pop();
    cout << st.peek() << endl; // 21

    st.pop(); // 22
    st.pop();
    cout << st.peek(); // Stack Is Empty ( -1 )

    if (st.isEmpty())
    {
        cout << " Stack is Empty " << endl;
    }
    else
    {
        cout << " Stack is Not Empty " << endl;
    }

    st.push(22);
    st.push(21);
    st.push(20);
    st.push(19);
    st.push(18);
    st.push(17);  //  Stack OverFlow as the size of stack is 5 

    return 0;
}

 