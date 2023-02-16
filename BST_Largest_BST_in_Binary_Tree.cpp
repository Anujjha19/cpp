#include <bits/stdc++.h> 

/*     
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };
 */


class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve( TreeNode<int>* root , int &ans){
    if(root==NULL) {
        return{ INT_MIN , INT_MAX , true , 0};
    }
    info left = solve( root -> left , ans); 
    info right=solve( root -> right , ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max( root -> data , right.maxi);
    currNode.mini = min( root -> data , left.mini);

    if( left.isBST && right.isBST && ( (root->data  > left.maxi) && ( root ->data <  right.mini) )){

        currNode.isBST= true;
    
    }else{ 
                currNode.isBST= false;

    }
    
    
    if( currNode.isBST){
        ans = max( ans , currNode.size );
    }

return currNode;

}



int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    int maxSize=0;

    info temp = solve( root , maxSize);

    return maxSize;



}

/* 

class NodeValue {
public:
    int maxNode, minNode, maxSize;
    
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution {
private:
    NodeValue largestBSTSubtreeHelper(TreeNode* root) {
        
        - An empty tree is a BST of size 0.
        
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        
        
        - Get values from left and right subtree of current tree.
        
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        
        -  Current node is greater than max in left AND smaller than min in right, it is a BST.

        if (left.maxNode < root->val && root->val < right.minNode) {
            
            -It is a BST.

            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), 
                            left.maxSize + right.maxSize + 1);
        }
        
        -
        
         Otherwise, return [-inf, inf] so that parent can't be valid BST
        
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    public:
    int largestBSTSubtree(TreeNode* root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};


 */