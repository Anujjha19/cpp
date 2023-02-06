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
void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void flatten(Node *root)
{
    // code here
    Node *curr = root;
    while (curr != NULL)
    {

        if (curr->left)
        {
            Node *pred = curr->left;

            while (pred->right)
                pred = pred->right;

            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }

    /* //Left Part Null
    curr = root ;
    while( curr != NULL){
        curr -> left =NULL;
        curr = curr -> right;
    } */

}

int main()
{

    Node *root = NULL;
    root = buildTree(root);


    cout << "Flatten : " << endl;

    flatten(root);
    inorder(root);

    return 0;
}

/*
        T . C - O( N )
        S . C - O( 1 )
 */