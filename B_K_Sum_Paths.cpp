
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


void solveSumK( Node* root , int &count,int k , vector<int> path ){
        if (root == NULL) return ;
        path.push_back(root -> data);
        
    solveSumK( root -> left , count , k , path);
         solveSumK( root -> right , count , k , path);
        
        int size = path.size();
        int sum =0;
        for( int i= size-1; i>=0 ; i--){
            sum+=path[i];
            if( sum == k) {
                count++;
            }
        } 
        
        // path.pop_back();
        // We should not do it as we are not passing it by refernce
        
     
    }
  
    int sumK(Node *root,int k)
    {
        
        int count =0;
        vector<int> path;
        
        solveSumK(root  , count , k , path);
        return count;
        
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
    int k= 13;
    
    cout << " K Path Sum  : " << sumK( root , k) << endl;

    return 0;
}
