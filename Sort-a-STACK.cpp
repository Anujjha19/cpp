void sortedInsert(stack<int> &stack, int num)
{
    // base case
    if (stack.empty() || (!stack.empty() && stack.top() < num))
    {
        stack.push(num);
        return;
    }

    int n = stack.top();
    stack.pop();

    // recusrive call
    sortedInsert(stack, num);

    stack.push(n);
}

void sortStack(stack<int> &stack)
{
    // base case
    if (stack.empty())
    {
        return;
    }

    int num = stack.top();
    stack.pop();

    // recursive call
    sortStack(stack);

    sortedInsert(stack, num);
}

// t.c = O(n2)
// s.c = O(n)

/*
    Time Complexity: O(N^2)
    Space Complexity: O(N),

    where N is the number of elements in the stack.

void sortedInsert(stack<int> &stack, int current)
{
    if (stack.empty() || current > stack.top())
    {
        stack.push(current);
        return;
    }

    // Remove the top element
    int top = stack.top();
    stack.pop();
    // Recursion for the remaining elements in the stack
    sortedInsert(stack, current);
    // Insert the popped element back in the stack
    stack.push(top);
}

// Recursive method to sort a stack
void sortStack(stack<int> &stack)
{
    // Base case: stack is empty
    if (stack.empty())
    {
        return;
    }

    // Remove the top element
    int top = stack.top();
    stack.pop();
    // Recursion for the remaining elements in the stack
    sortStack(stack);
    // Insert the popped element back in the sorted stack
    sortedInsert(stack, top);
}
*/

Solution approach 1 : Using a temporary stack
stack sortStack(stack s)

{

    stack tempStack

        while (1s.empty())

    {
        int topInputStack = s.pop() while (!tempstack.empty() && tempStack.top() > topInputStack){
            int topTempStack = tempStack.pop()
            s.push(topTempStack)
            } 
            tempStack.push(topInputStack)
    }

    return tempStack
}// t.c = O(n2)
// s.c = O(n)