
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
int findMax(Node *root)
{
    if (root == NULL)
    {
        return INT16_MIN;
    }
    else
    {
        int ans = max(root->data, max(findMax(root->right), findMax(root->left)));
        return ans;
    }
}

int findMin(Node *root)
{
    if (root == NULL)
    {
        return INT16_MAX;
    }
    else
    {
        int ans = min(root->data, min(findMin(root->right), findMin(root->left)));

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

    int max = findMax(root);
    cout << " Max in a given Tree is : " << max << endl;

    int min = findMin(root);
    cout << " Min in a given Tree is : " << min << endl;
    return 0;
}
