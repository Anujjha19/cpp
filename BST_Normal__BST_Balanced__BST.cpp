
void inorder(vector<int>& traversal, Node* parent)
{
	// Base Case
	if (parent == NULL)
		return;

	inorder(traversal, parent->left);
	// Storing the values in the vector
	traversal.push_back(parent->data);

	inorder(traversal, parent->right);
}

Node* NewTree(int s , int e ,vector<int> &in) {
    if( s> e ) return NULL;

    int mid = ( s+e)/2;

    Node* root = new Node(in[mid]);
    root ->left = NewTree( s , mid-1 , in);
    root ->right = NewTree( mid+1 , e , in);

    return root;
}

Node* buildBalancedTree(Node* root)
{
	// Code here
	vector<int> traversal;
    inorder( traversal , root);

    return NewTree( 0 , traversal.size()-1 , traversal);


}