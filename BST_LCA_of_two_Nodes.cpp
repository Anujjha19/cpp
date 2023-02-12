/* // TLE
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    // Write your code here
    if( root==NULL || root ==P || root ==Q){
        return root;
    }

TreeNode<int>* left =  LCAinaBST(root ->left,P, Q);
TreeNode<int>* right =  LCAinaBST(root ->right,  P, Q);

    if(left ==NULL )return right;
    else if( right ==NULL )return left;
    else return root;

}   */

/* //Recursive
if( root ==NULL) return NULL;

    if( root -> data < P->data && root-> data < Q->data){
 return LCAinaBST(root ->right,P, Q);

    }
    else if( root -> data > P->data && root-> data >Q->data){
  return LCAinaBST(root ->left,  P, Q);

    }else{
        return root;
    }
 */

// Irerative
while (root != NULL)
{
    if (root->data < P->data && root->data < Q->data)
    {
        root = root->right;
    }
    else if (root->data > P->data && root->data > Q->data)
    {
        root = root->left;
    }
    else
    {
        return root;
    }
}
