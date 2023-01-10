#include <iostream>
#include<vector>
using namespace std;
/* 
void solve(vector<int> arr ,vector<int> output, int index,vector<vector<int>& ans; ){
//base case
if(index >=arr.size()){
    ans.push_back(output);
    return;
}
//exclude
solve(arr , output , index+1, ans);

//include
int element=arr[index];
output.push_back(element);
solve(arr , output , index+1, ans);

}
vector<vector<int>> subsets(vector<int>& arr){
    vector<vector<int> ans;
    vector<int> output;
    int index=0;
    solve(arr, output , index , ans);

    return ans;
    } */


int main()
{

    int arr[3] = {1,2,3};
    int n = 3;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    
    subsets(arr, n)

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
/* 
class Solution {
private:
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int> >& ans) {
        //base case
        if(index >= nums.size()) {
            ans.push_back(output);
            return ;
        }
        
        //exclude
        solve(nums, output, index+1, ans);
        
        //include
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index+1, ans);
        
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int> > ans;
        vector<int> output;
        int index = 0;
        solve(nums, output, index, ans);
        return ans;
        
    }
}; */