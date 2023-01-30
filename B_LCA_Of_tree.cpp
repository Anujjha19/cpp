
#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* lca(Node *root, int n1, int n2)
{

    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *leftAns = lca(root->left, n1, n2);
    Node *rightAns = lca(root->right, n1, n2);

    if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    else if (leftAns == NULL && rightAns != NULL)
    {
        return rightAns;
    }
    else if (leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    Node *root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    int n1 = 10;
    int n2 = 14;
    Node* LCA = lca(root, n1, n2);
    cout << " LCA of A Tree : " << LCA -> data<< endl;

    return 0;
}
/* 
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if( root ==NULL || root == p || root == q){
            return root;
        }

        TreeNode* Left = lowestCommonAncestor( root -> left , p , q );
        TreeNode* Right = lowestCommonAncestor( root -> right , p , q );

        if( Left == NULL) return Right;
        else if( Right == NULL) return Left;
        else return root;
    } */