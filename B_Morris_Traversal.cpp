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

void MorrisTraversal(Node *root)
{
    Node *current;
    Node *predessor;

    if (root == NULL)
        return;

    current = root;
    while (root != NULL)
    {

        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }

        else
        {
            predessor = current->left;
            while (predessor->right != NULL && predessor->right != current)
                predessor = predessor->right;

            if (predessor->right == NULL)
            {
                predessor->right = current;
                current = current->left;
            }
            else
            {
                predessor->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

vector<int> getInorder(Node *root)
{
    vector<int> inorder;

    Node *curr = root;
    while (curr != NULL)
    {

        if (curr->left == NULL)
        {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *prev = curr->left;

            while (prev->right != NULL && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = curr;
                //For PreORDER  --  Preorder.push_back(curr->data);
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return inorder;
}

int main()
{

    Node *root = NULL;
    root = buildTree(root);

    MorrisTraversal(root);

    vector<int> inorderAns;
    inorderAns = getInorder(root);

    cout << "The Inorder Traversal is: ";
    for (int i = 0; i < inorderAns.size(); i++)
    {
        cout << inorderAns[i] << " ";
    }

    return 0;
}

/*
        T . C - O( N )
        S . C - O( 1 )
 */