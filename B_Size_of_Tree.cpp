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

int getSize(Node *root)
{
    if(root ==NULL){
        return 0;
    }
    else{
        int ans = 1 + getSize(root -> right) + getSize(root -> left);
        return ans;
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

    int ans = getSize(root);
    cout << " Size Of given Tree is : " << ans << endl;
    return 0;
}
