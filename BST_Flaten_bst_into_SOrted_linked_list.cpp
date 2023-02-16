// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Node of the binary tree
struct node {
	int data;
	node* left;
	node* right;
	node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

// Function to print flattened
// binary Tree
void print(node* parent)
{
	node* curr = parent;
	while (curr != NULL)
		cout << curr->data << " ", curr = curr->right;
}

// Function to perform in-order traversal
// recursively
void inorder(vector<int>& traversal, node* parent)
{
	// Base Case
	if (parent == NULL)
		return;

	inorder(traversal, parent->left);
	// Storing the values in the vector
	traversal.push_back(parent->data);

	inorder(traversal, parent->right);
}

node* flatten(node* parent)
{
    vector < int> ans;
    inorder( ans , parent);

    node* newRoot = new node(ans[0]);
    
    node* curr = newRoot ;
    for( int i=1; i<ans.size() ; i++){
        node* temp = new node(ans[i]) ;
        curr->right = temp ;
        curr->left = NULL;
        curr = temp;
    }
    curr ->left =NULL;
    curr ->right =NULL;

    return newRoot;


}

int main()
{

	node* root = new node(5);
	root->left = new node(3);
	root->right = new node(7);
	root->left->left = new node(2);
	root->left->right = new node(4);
	root->right->left = new node(6);
	root->right->right = new node(8);

	// Calling required function
	print(flatten(root));

	return 0;
}
