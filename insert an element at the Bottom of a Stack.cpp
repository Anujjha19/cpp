#include <bits/stdc++.h> 

void solve( stack<int>& s, int x){
    //Base Case
    if(s.empty()){
        s.push(x);
        return;
    }
    int num= s.top();
    s.pop();
    //Recursive Call
    solve(s, x);
     s.push(num);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    solve (myStack , x);
    return myStack;
}
// Time Complexity: O(N), where N is the total number of elements in the stack. 
// Auxiliary Space: O(N) 

