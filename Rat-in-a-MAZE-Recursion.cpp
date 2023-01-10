//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    bool issafe(vector<vector<int>> &m, int n,int x, int y,vector<vector<int>> visited){
        if((x>=0 && x<n)&&(y<n && y>=0) && visited[x][y]==0 && m[x][y]==1){
            return true;
        }else{
            return false;
        }
    }
    void solve(vector<vector<int>> &m, int n,int x, int y, vector<string> &ans,
    vector<vector<int>> visited,string str){
        if(x==n-1 && y==n-1){
            ans.push_back(str);
            return;
        }
        visited[x][y] = 1;
        // down
        int newx = x+1;
        int newy = y;
        if(issafe(m,n,newx,newy,visited)){
            str.push_back('D');
            solve(m,n,newx,newy,ans,visited,str);
            str.pop_back();
        }
        // up
         newx = x-1;
         newy = y;
        if(issafe(m,n,newx,newy,visited)){
            str.push_back('U');
            solve(m,n,newx,newy,ans,visited,str);
            str.pop_back();
        }
        // left
         newx = x;
         newy = y-1;
        if(issafe(m,n,newx,newy,visited)){
            str.push_back('L');
            solve(m,n,newx,newy,ans,visited,str);
            str.pop_back();
        }
        // right
         newx = x;
         newy = y+1;
        if(issafe(m,n,newx,newy,visited)){
            str.push_back('R');
            solve(m,n,newx,newy,ans,visited,str);
            str.pop_back();
        }
        visited[x][y] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0]==0){
            return ans;
        }
        vector<vector<int>> visited(n,vector<int>(n,0));
        int srcx = 0, srcy = 0;
        string str = "";
        solve(m,n,srcx,srcy,ans,visited,str);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends