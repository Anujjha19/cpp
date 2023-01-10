/* 
    Time Complexity: O(N! * log(N!))
    Space complexity: O(N * N!)
    
    Where N is the length of the given string.


#include <algorithm>

void generatePermutationsHelper(string &str, int l, int r, vector<string> &ans)
{
    // base case
    if (l == r)
    {
        ans.push_back(str);
        return;
    }
    for (int i = l; i <= r; i++)
    {
        swap(str[l], str[i]);
        generatePermutationsHelper(str, l + 1, r, ans);
        // backtrack
        swap(str[l], str[i]);
    }
}

vector<string> generatePermutations(string &str)
{
    // stores the permutations of the string
    vector<string> ans;

    int l = 0;
    int r = str.size() - 1;

    // call the recursive function
    generatePermutationsHelper(str, l, r, ans);

    // lexicographically increasing order
    sort(ans.begin(), ans.end());

    return ans;
} */


class Solution {
private:
    void solve(vector<int> nums, vector<vector<int>>&ans , int index){
        //Base Case
        if(index >=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=index ; j<nums.size() ;j++){
            swap(nums[index] , nums[j]);
            solve(nums , ans, index+1);
            //backtrack
            swap(nums[index], nums[j]);
        }
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        solve(nums , ans , index);
        return ans;
    }
};

/* #include <iostream>
using namespace std;
 
// Function to find all permutations of a given string `str[i…n-1]`
// containing all distinct characters
void permutations(string str, int i, int n)
{
    // base condition
    if (i == n - 1)
    {
        cout << str << endl;
        return;
    }
 
    // process each character of the remaining string
    for (int j = i; j < n; j++)
    {
        // swap character at index `i` with the current character
        swap(str[i], str[j]);        // STL `swap()` used
 
        // recur for substring `str[i+1, n-1]`
        permutations(str, i + 1, n);
 
        // backtrack (restore the string to its original state)
        swap(str[i], str[j]);
    }
}
 
int main()
{
    string str = "ABC";
 
    permutations(str, 0, str.length());
 
    return 0;
} */