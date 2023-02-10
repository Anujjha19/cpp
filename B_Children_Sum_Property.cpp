#include <iostream>
#include <queue>
#include <map>
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
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void reorder(Node *root)
{
    if (root == NULL)
        return;

    int child = 0;
    if (root->left)
    {
        child += root->left->data;
    }
    if (root->right)
    {
        child += root->right->data;
    }

    if (child >= root->data)
    {
        root->data = child;
    }
    else
    {
        if (root->left)
            root->left->data = child;
        else if (root->right)
            root->right->data = child;
    }

    reorder(root->left);
    reorder(root->right);

    int total = 0;

    if (root->left)
        total += root->left->data;
    if (root->right)
        total += root->right->data;

    if (root->left || root->right)
        root->data = total;
}
void printTree(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}
void changeTree(Node *root)
{
    reorder(root);
}

int main()
{

    Node *root = NULL;
    root = buildTree(root);
    cout << endl;
    printTree(root);
    changeTree(root);
    cout << endl;
    printTree(root);

    return 0;
}
