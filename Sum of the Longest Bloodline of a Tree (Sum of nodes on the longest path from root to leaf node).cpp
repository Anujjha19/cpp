
#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int sumOfLongRootToLeafPath(Node *root)
    {
       int len , maxLen , sum , maxSum =0;
       
       solve(root , len, maxLen , sum , maxSum);
       
       return maxSum;
    }
    
    void solve(Node* root , int len , int &maxLen , int sum , int &maxSum){
        if( root == NULL){
            if ( len > maxLen){
                maxLen =len;
                maxSum =sum;
            }
            else if ( len ==maxLen ){
                maxSum = max ( sum , maxSum);
            }
            return;
        }
        sum = root -> data  + sum;
        
        solve( root -> left , len+1 , maxLen , sum , maxSum);
    
        solve( root -> right , len+1 , maxLen , sum , maxSum);
    }

int main()
{
    Node *root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);

    int max = sumOfLongRootToLeafPath(root);
    cout << " Sum of Long Root To Leaf : " << max << endl;

    return 0;
}
