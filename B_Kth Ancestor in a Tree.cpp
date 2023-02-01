
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
Node *solve(Node *root, int &k, int node)
{
    if (root == NULL)
        return NULL;

    if (root->data == node)
        return root;

    Node *left = solve(root->left, k, node);
    Node *right = solve(root->right, k, node);

    if (left != NULL && right == NULL)
    {
        k--;
        if (k <= 0)
        {

            // Itna Baada Dobara -- kr k kik will not come close to it
            // Lock the root

            k = INT16_MAX;
            return root;
        }
        return left;
    }

    if (left == NULL && right != NULL)
    {
        k--;
        if (k <= 0)
        {

            // Itna Baada Dobara -- kr k kik will not come close to it
            // Lock the root answer

            k = INT16_MAX;
            return root;
        }
        return right;
    }

    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here

    Node *ans = solve(root, k, node);

    // For Root Node where k greater than 0
    if (ans == NULL || ans->data == node)
        return -1;

    else
    {
        return ans->data;
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
    int k = 2;
    int node = 14;

    cout << " K Path Sum  : " << kthAncestor(root, k, node) << endl;

    return 0;
}
