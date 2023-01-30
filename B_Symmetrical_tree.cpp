
    bool isSymmetric(TreeNode* root) {
        
        if(root==NULL) return true; //Tree is empty
        
        return isSymmetricTest(root->left,root->right);
    }
    
    bool isSymmetricTest(TreeNode* p , TreeNode* q){
        if(p == NULL && q == NULL) //left & right node is NULL 
            return true; 
        
        else if(p == NULL || q == NULL) //one of them is Not NULL
            return false; 
        
        else if(p->val!=q->val) 
            return false;
        
        return isSymmetricTest(p->left,q->right) && isSymmetricTest(p->right,q->left); 
    }

/* 
bool helper(TreeNode *left, TreeNode *right)
{
    if (left == NULL || right == NULL)
        return left == right;

    return (helper(left.left, right.right) && helper(left.right, right.left));
}

bool isSymmetric(TreeNode *root)
{
    return (root == NULL || helper(root->left, root->right));
} */