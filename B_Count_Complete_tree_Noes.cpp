#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {

        this->data = d;
        Node *left = NULL;
        Node *right = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "Enter Root :- ";
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}


int leftH(Node *node)
{
    int height = 0;
    // if(node==NULL) return 0;
    while (node)
    {
        height++;
        node = (node->left);
    }
    return height;
}
int rightH(Node *node)
{
    int height = 0;
    // if(node==NULL) return 0;
    while (node)
    {
        height++;
        node = (node->right);
    }
    return height;
}
int countNodes(Node *root)
{

    if (root == NULL)
        return 0;

    int left = leftH(root);
    int right = rightH(root);

    if (left == right)
        return (1 << left) - 1;
    return (1 + countNodes(root->left) + countNodes(root->right));
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);

    int Nodes = countNodes(root);

    cout << "Nodes :- " << Nodes;

    return 0;
}

/* 5
1 -1 3 */