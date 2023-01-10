// Initial template for C++

//T.C == O(n)
//S.C == O(n)
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
private:
    bool knows(vector<vector<int>> &M, int a, int b, int n)
    {
        if (M[a][b] == 1)
            return true;
        else
            return false;
    }

public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> s;
        // step1: push all element in stack
        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }

        // step2: get 2 elements and copare them

        while (s.size() > 1)
        {

            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            if (knows(M, a, b, n))
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }
        int ans = s.top();
        // step3: single element in stack is potential celeb
        // so verify it

        // Row Check
        int zeroCount = 0;

        for (int i = 0; i < n; i++)
        {
            if (M[ans][i] == 0)
                zeroCount++;
        }

        // all zeroes
        if (zeroCount != n)
            return -1;

        // column check
        int oneCount = 0;

        for (int i = 0; i < n; i++)
        {
            if (M[i][ans] == 1)
                oneCount++;
        }
        // all ones
        if (oneCount != n - 1)
            return -1;

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}
// } Driver Code Ends

/* 

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
#include<stack>
class Solution 
{   
    private:
    
    bool knows(vector<vector<int> >& M, int n  , int a , int b){
        if(M[a][b]==1)
        return true ;
        
        else
        return false;
    }
     public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>s;
        //Step1 - push all element in stack
        for(int i=0; i<n; i++){
            s.push(i);
        }
        //Step2 - get 2 element nd compare
        while(s.size() > 1){
            int a=s.top();
            s.pop();
            
            int b=s.top();
            s.pop();
            
            if(knows(M , n , a , b)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        
        int celebrity=s.top();
        //Step3- single element in stack may be the celebrity
        //so verify it
        
        //Row Check
        bool rowCheck=false;
        int zeroCount=0;
        
        for(int i=0; i< n; i++){
            if(M[celebrity][i] ==0)
            zeroCount++;
        }
        //all zeroes
        if(zeroCount==n){
            rowCheck=true;
        }
        
         //Column Check
        bool colCheck=false;
        int oneCount=0;
        
        for(int i=0; i< n; i++){
            if(M[i][celebrity] ==1)
            oneCount++;
        }
        //all ones
        if(oneCount==n-1){
            colCheck=true;
        }
        
        if(rowCheck == true && colCheck == true){
            return celebrity;
        }
        
        else{
            return -1;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends */