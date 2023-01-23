#include <bits/stdc++.h>
using namespace std;

/*  TC - O ( N square )
class Solution{

    private:
    int height(Node* root){
        if(root==NULL)
{   return 0;
    }
    int l= height(root -> left);
    int r= height( root -> right);
    int ans= max(l , r) +1;

    return ans;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if(root==NULL) return true;

        bool l = isBalanced( root -> left);
        bool r = isBalanced( root -> right);

        bool diff= abs(height(root-> left) - height(root -> right)) <= 1;

            if( l && r && diff) {return true;}
            else{ return false;}
    }
    };

 */

// TC - O ( N )
class Solution
{

public:
    pair<bool, int> isBalancedOptimized(Node *root)
    {
        if (root == NULL)
        {
            pair<bool, int> ans = make_pair(true, 0);
            return ans;
        }
        pair<bool, int> left = isBalancedOptimized(root->left);
        pair<bool, int> right = isBalancedOptimized(root->right);

        bool leftVal = left.first;
        bool rightVal = right.first;
        bool diffVal = abs(left.second - right.second) <= 1;

        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1;

        if (leftVal && rightVal && diffVal)
            ans.first = true;

        else
            ans.first = false;

        return ans;
    }

    bool isBalanced(Node *root)
    {

        return isBalancedOptimized(root).first;
    }
};

// TC - O ( N ) using Just Height {Striver}
bool isBalanced(TreeNode *root)
{
    return dfsHeight(root) != -1;
}
int dfsHeight(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = dfsHeight(root->left);
    if (leftHeight == -1)
        return -1;
    int rightHeight = dfsHeight(root->right);
    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;
    return max(leftHeight, rightHeight) + 1;
}