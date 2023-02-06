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

void MorrisTraversal(Node* root ){
    Node* current ;
    Node* predessor;

    if( root ==NULL) return;

    current = root;
    while( root != NULL){
        
        if( current -> left ==NULL ){
            cout << current -> data << " ";
            current = current -> right;
        }

        else{
            predessor = current -> left;
            while( predessor -> right != NULL &&  predessor -> right != current)
                predessor = predessor -> right;

                if(predessor -> right ==NULL){
                    predessor ->right=current;
                    current = current->left;
                }
                else{
                    predessor->right =NULL;
                    cout<< current -> data << " ";
                    current = current -> right;
                }
            }
        }
}

int main()
{

    Node *root = NULL;
    root = buildTree(root);

    MorrisTraversal(root);

    return 0;
}

/* 
        T . C - O( N )
        S . C - O( 1 )
 */