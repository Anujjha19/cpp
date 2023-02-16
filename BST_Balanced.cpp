#include <algorithm>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

int height(Node *root)
{
    if (!root)
        return 0;
    return 1 + std::max(height(root->left), height(root->right));
}

bool isBalanced(Node *root)
{
    if (!root)
        return true;
    int heightDiff = std::abs(height(root->left) - height(root->right));
    if (heightDiff > 1)
        return false;
    else
        return isBalanced(root->left) && isBalanced(root->right);
}

int main()
{
    // Example binary search tree
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    std::cout << (isBalanced(root) ? "Balanced" : "Not balanced") << std::endl;
    return 0;
}