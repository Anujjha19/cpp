#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
pair<int, int> solve(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> res;

    res.first = root->key + left.second + right.second;
    res.second = max(left.first, left.second) + max(right.first, right.second);

    return res;
}

int getMaxSum(Node *root)
{

    pair<int, int> ans = solve(root);

    return max((ans.first), (ans.second));
}
int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root -> left -> left= new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    inorder(root);

    cout << endl;

    int ANS = getMaxSum( root );

    cout << ANS << endl;
}