
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

bool isBST(Node *root, int min, int max)
{
    if (root == NULL)
        return true;

    if (root->data >= min && root->data <= max)
    {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }
    else
    {
        return false;
    }
}

bool isValidBST(Node *root)
{
    return isBST(root, INT_MIN, INT_MAX);
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to make a BST (end with -1): " << endl;
    takeInput(root);

    cout << "Printing BST: " << endl;
    levelOrderTraversal(root);

    if (isValidBST(root))
        cout << " TRUE ";
    else
        cout << " FALSE ";

    return 0;
}

// 10 8 21 7 27 5 4 3 -1
