
#include<iostream>
using namespace std;
#include<queue>
#include<stack>

queue<int> modifyQueue(queue<int> q, int k) {
    
    //Pop first k element from Queue and put inyto Stack 
    stack<int> s;
    for(int i=0 ; i< k; i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }
    //Fetch from stack and push to Queue
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
    }
    //fetchh first (n-k ) elements from queue and push back
    int n= q.size();
    
    int t= n-k;
    while(t--){
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
    
}
//TC- O(N);
//SC - O(K)