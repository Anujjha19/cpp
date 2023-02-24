/* C++ program to checks if a
binary tree is max heap or not */

#include <bits/stdc++.h>
using namespace std;

/* Tree node structure */
struct Node
{

	int data;
	struct Node *left;
	struct Node *right;
};

/* Helper function that
allocates a new node */
struct Node *newNode(int k)
{
	struct Node *node = new Node;
	node->data = k;
	node->right = node->left = NULL;
	return node;
}

int countNodes(Node *root)
{
	if (root == NULL)
		return 0;

	int ans = 1 + countNodes(root->left) + countNodes(root->right);

	return ans;
}

bool isCBT(Node *root, int i, int noOfNode)
{
	if (root == NULL)
		return true;

	if (i >= noOfNode)
		return false;
	else
	{
		bool left = isCBT(root->left, 2 * i + 1, noOfNode);
		bool right = isCBT(root->right, 2 * i + 2, noOfNode);

		return (left && right);
	}
}

bool isMaxHeap(Node *root)
{

	if (root->left == NULL && root->right == NULL)
		return true;
	if (root->right == NULL)
	{
		return (root->data > root->left->data);
	}
	else
	{
		if ((root->data > root->left->data && root->data > root->right->data) &&
			isMaxHeap(root->left) && isMaxHeap(root->right))
		{
			return true;
		}
		else
			return false;
	}
}

bool isHeap(Node *tree)
{

	int i = 0;
	int totalNodes = countNodes(tree);

	if (isCBT(tree, i, totalNodes) && isMaxHeap(tree))
		return true;

	else
		return false;
}
// Driver's code
int main()
{
	Node *root = NULL;
	root = newNode(10);
	root->left = newNode(9);
	root->right = newNode(8);
	root->left->left = newNode(7);
	root->left->right = newNode(6);
	root->right->left = newNode(5);
	root->right->right = newNode(4);
	root->left->left->left = newNode(3);
	root->left->left->right = newNode(2);
	root->left->right->left = newNode(1);

	// Function call
	if (isHeap(root))
		cout << "Given binary tree is a Heap\n";
	else
		cout << "Given binary tree is not a Heap\n";

	return 0;
}

// This code is contributed by shubhamsingh10
