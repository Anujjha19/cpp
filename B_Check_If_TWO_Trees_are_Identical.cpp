#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
};
node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}
/* 
int identicalTrees(node *a, node *b)
{
    if (a == NULL && b == NULL)
        return 1;

    if (a != NULL && b != NULL)
    {
        return (a->data == b->data && identicalTrees(a->left, b->left) && identicalTrees(a->right, b->right));
    }
    return 0;
} */

    bool isIdentical(node *a, node *b)
    {
        if(a==NULL && b ==NULL) return  1;
        if(a!=NULL && b==NULL) return 0;
        if(a==NULL && b != NULL) return 0;
        
        bool left = isIdentical(a -> left, b -> left);
        bool right = isIdentical(a ->right, b ->right);
        
        bool CompareRootValue = ( a -> data == b -> data);
        
        if( left && right && CompareRootValue ) return 1;
        else return 0;
    }

int main()
{
    node *root1 = newNode(1);
    node *root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);

    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    // Function call
    //if (identicalTrees(root1, root2))
    if (isIdentical(root1, root2) ==1 )
        cout << "Both trees are identical.";
    else
        cout << "Trees are not identical.";

    return 0;
}