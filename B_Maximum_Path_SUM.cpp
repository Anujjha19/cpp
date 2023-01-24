#include<iostream>
using namespace std;

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi= INT_MIN;
        checkMaxPathSum( root , maxi);

        return maxi;
    }
    int checkMaxPathSum(TreeNode* root , int &maxi){

        if (root ==NULL) return 0;
        
        /*  This is be ok For most of the cases , But if path has Negative values then It can never give you Maximum Path. So If we get -ve values we will immediatelty retuen 0 
        int left = checkMaxPathSum(root-> left , maxi);
        int right = checkMaxPathSum(root-> right , maxi);
         */
        int left = max(0 , checkMaxPathSum(root-> left , maxi));
        int right = max(0 , checkMaxPathSum(root-> right , maxi));

        //From Which Node Is Getting Max Value 
        maxi = max( maxi , left + right + root -> val);

        //Now Getting which path to follow Left or Right
        return (root ->val +max (left , right));
    }
};
