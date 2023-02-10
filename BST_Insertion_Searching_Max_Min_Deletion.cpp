
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
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left)
        inorder(root->left);
    cout << root->data << " ";
    if (root->right)
        inorder(root->right);
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // Current level is complete, print a new line
            cout << endl;
            if (!q.empty())
            {
                // Queue still has some child nodes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// Inserting a Node

Node *insertIntoBST(Node *root, int d)
{
    // Make first node in the BST
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// Searching a NODE
bool searchRecursive(Node *root, int x)
{
    // Your code here

    if (root == NULL)
        return false;

    if (root->data == x)
        return true;

    if (x < root->data)
    {
        return searchRecursive(root->left, x);
    }
    else
    {
        return searchRecursive(root->right, x);
    }
}
bool searchIterative(Node *root, int x)
{
    Node *temp = root;
    while (temp != NULL)
    {

        if (temp->data == x)
            return true;

        if (x < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}

// MIN Node
Node *minValue(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

// MAX value
Node *maxValue(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
/*
int minValue(Node *root)
{
    int res = -1;
    while (root)
    {
        res = root->data;
        root = root->left;
    }
    return res;
}
int maxValue(Node *root)
{
    int res = -1;
    while (root)
    {
        res = root->data;
        root = root->right;
    }
    return res;
} */

// Deleting a NODE

Node *deleteNode(Node *root, int X)
{
    if (root == NULL)
        return root;
    if (root->data == X)
    {

        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // Only  left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root->left;
            return temp;
        }

        // Only  right child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root->right;
            return temp;
        }

        // Both 2 Child
        if (root->left != NULL && root->right != NULL)
        {

            int mini = minValue(root->right)->data;
            root->data = mini;

            root->right = deleteNode(root->right, mini);
        }
    }
    else if (X > root->data)
    {
        root->right = deleteNode(root->right, X);
    }
    else
    {
        root->left = deleteNode(root->left, X);
    }

    return root;
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to make a BST (end with -1): " << endl;
    takeInput(root);

    cout << "Printing BST: " << endl;
    levelOrderTraversal(root);

    cout << " Min Node : " << minValue(root)->data << endl;
    cout << " Max Node : " << maxValue(root)->data << endl;

    cout << "Key To Search : ";
    int key;
    cin >> key;

    cout << " Nodes is Present :- " << key << " : ";

    // if (searchIterative(root, key))
    if (searchRecursive(root, key))
        cout << " YES ";
    else
        cout << " NO ";

    cout << "Node To Delete : ";
    int node;
    cin >> node;
    deleteNode(root, node);

    cout << "Printing BST after Deleting a Node " << node << ": " << endl;
    levelOrderTraversal(root);

    return 0;
}

// 10 8 21 7 27 5 4 3 -1
