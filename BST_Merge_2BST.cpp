void inorder(Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

vector<int> merge2Array(vector<int> &v1, vector<int> &v2)
{
    vector<int> ans;

    int i = 0, j = 0;

    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] < v2[j])
        {
            ans.push_back(v1[i]);
            i++;
        }
        else
        {
            ans.push_back(v2[j]);
            j++;
        }
    }

    while (i < v1.size())
    {
        ans.push_back(v1[i]);
        i++;
    }
    while (j < v2.size())
    {
        ans.push_back(v2[j]);
        j++;
    }

    return ans;
}

vector<int> merge(Node *root1, Node *root2)
{
    vector<int> v1;
    vector<int> v2;

    inorder(root1, v1);
    inorder(root2, v2);

    return merge2Array(v1, v2);
}





/* 
#include <bits/stdc++.h> 

void inorder( TreeNode<int> *root , vector<int>&in ){
    if(root==NULL) return;

    inorder( root->left , in);
    in.push_back(root->data);
    inorder(root->right,in);
}
vector<int> merge2Array(vector<int>&a , vector<int>&b ){
    int i , j ,k=0;
    vector<int>ans(a.size()+ b.size());


    while( i< a.size() && j<b.size()){
        if(a[i] < b[j]){
            ans[k++]= a[i];
            i++;
        }
        else{
            ans[k++]= b[j];
            j++;
        }
    }
    while(i<a.size()){
ans[k++]= a[i];
            i++;
    }
    while( j <b.size() ){
ans[k++]= b[j];
            j++;
    }
    return ans;
    
}
TreeNode<int> *inorderToBST(int s ,int e , vector<int> &mergeArr){
    if( s> e) return NULL;

    int mid=(s+e)/2;

    TreeNode<int> *root = new TreeNode<int>(mergeArr[mid]);
    root->left= inorderToBST(s, mid-1, mergeArr);                                 
    root->right= inorderToBST(mid+1,e, mergeArr); 

    return root;

}


TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    
    vector<int> bst1, bst2;
    inorder( root1 , bst1);
    inorder(root2 , bst2);

    vector<int> mergeArray= merge2Array( bst1, bst2);



int s =0;
int e= mergeArray.size()-1;

return inorderToBST( s, e, mergeArray);
    
}
 */