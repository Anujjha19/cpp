// C++ implementation to convert the given
// BST to Min Heap

#include <bits/stdc++.h>
using namespace std;

// Structure of a node of BST
struct Node
{

	int data;
	Node *left, *right;
};

/* Helper function that allocates a new node
with the given data and NULL left and right
pointers. */
struct Node *getNode(int data)
{
	struct Node *newNode = new Node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void inorderTraversal(Node *root, vector<int> &arr)
{
	if (root == NULL)
	{
		return;
	}

	inorderTraversal(root->left, arr);	// Left Call
	arr.push_back(root->data);			// Root Data
	inorderTraversal(root->right, arr); // Right Call
}

void fillPreOrder(Node *root, vector<int> &inorder, int &index)
{
	if (root == NULL)
		return;
	root->data = inorder[index++];
	fillPreOrder(root->left, inorder, index);
	fillPreOrder(root->right, inorder, index);
}

Node *convertBST(Node *root)
{
	// Write your code here.

	vector<int> inorder;
	int i = 0;

	inorderTraversal(root, inorder);

	fillPreOrder(root, inorder, i);

	return root;
}

// Driver program to test above
int main()
{
	// BST formation
	struct Node *root = getNode(4);
	root->left = getNode(2);
	root->right = getNode(6);
	root->left->left = getNode(1);
	root->left->right = getNode(3);
	root->right->left = getNode(5);
	root->right->right = getNode(7);

	vector<int> arr;
	// Function call
	inorderTraversal(root, arr);

	cout << "Preorder Traversal:" << endl;
	Node * ans = convertBST(root);
	cout << ans -> data;


	return 0;
}

/*


void convert(BinaryTreeNode* root , 	vector<int> &inorder){
	if( root ==NULL) return ;

	convert( root -> left , inorder);
	inorder.push_back(root->data);
	convert( root -> right , inorder);
}

void fillPreOrder( BinaryTreeNode* root , vector<int>& inorder , int &index){
	if( root ==NULL) return;
root -> data = inorder[index++];
fillPreOrder( root ->left , inorder , index);
fillPreOrder( root ->right , inorder , index);

}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{

	vector<int> inorder;
	int i=0;

	convert( root , inorder);

	fillPreOrder( root , inorder , i);

	return root;




	
}
 */