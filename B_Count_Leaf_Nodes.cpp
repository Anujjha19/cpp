void inOrder(BinaryTreeNode<int> *root , int &count)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    
    inOrder(root->left, count);
    //leaf Node
    if( root-> left ==NULL && root-> right ==NULL){
count++;
    }
    inOrder(root->right, count);
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.
    int count =0;
    inOrder(root, count);
    return count;
    
    
    
}