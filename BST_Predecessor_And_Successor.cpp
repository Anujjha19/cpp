
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

void predecessor(Node *root, Node *&pre, int key)
{
    // Node * temp = NULL;
    while (root != NULL)
    {
        if (key <= root->data)
        {
            root = root->left;
        }
        else
        {
            pre = root;
            root = root->right;
        }
    }
}
void successor(Node *root, Node *&suc, int key)
{

    // Node * temp = NULL;
    while (root != NULL)
    {
        if (key >= root->data)
        {
            root = root->right;
        }
        else
        {
            suc = root;
            root = root->left;
        }
    }
}
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{

    // Your code goes here
    predecessor(root, pre, key);
    successor(root, suc, key);
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to make a BST (end with -1): " << endl;
    takeInput(root);

    cout << "Printing BST: " << endl;
    levelOrderTraversal(root);

    Node *pre = NULL;
    Node *suc = NULL;
    int key = 8;

    findPreSuc(root, pre, suc, key);
    
    if (pre != NULL)
        cout << pre->data;
        else  cout << -1;

    if (suc != NULL)
        cout << " " << suc->data << endl;

    else  cout << -1;

return 0;
}

// 10 8 21 7 27 5 4 3 -1
