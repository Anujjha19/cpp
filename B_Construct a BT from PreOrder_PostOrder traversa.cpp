#include <bits/stdc++.h>
using namespace std;

struct Node
{

    int data;
    struct Node *left;
    struct Node *right;

    Node(int d)
    {
        data = d;
        right = NULL;
        left = NULL;
    }
};

void printPreOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

/*
int findPosition( int in[] , int element , int n){
    for(int i=0; i< n ; i++){
    if ( in[i] == element) return i;
    }
    return -1;
}
*/
class Solution {
    public:
    
void createMapping(int in[], map<int, int> &nodeToIndex, int n)
{
    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
}

Node *solve(int in[], int post[], int &postIndex, int n, int inStart, int inEnd, map<int, int> &nodeToIndex)
{

    if ((inStart > inEnd) || (postIndex < 0))
    {
        return NULL;
    }
    int element = post[postIndex--];

    Node *root = new Node(element);
    // int position = findPosition( in , element , n);
    int position = nodeToIndex[element];

    root->right = solve(in, post, postIndex, n, position + 1, inEnd, nodeToIndex);
    root->left = solve(in, post, postIndex, n, inStart, position - 1, nodeToIndex);

    return root;
}
Node *buildTree(int in[], int post[], int n)
{
    // Your code here
    int postIndex = n - 1;
    map<int, int> nodeToIndex;

    createMapping(in, nodeToIndex, n);

    Node *ans = solve(in, post, postIndex, n, 0, n - 1, nodeToIndex);

    return ans;
}
};

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        int inOrder[n];
        int postOrder[n];

        for (int i = 0; i < n; i++)
        {
            cin >> inOrder[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> postOrder[i];
        }

        Solution obj;

        Node *root = obj.buildTree(inOrder, postOrder, n);

        printPreOrder(root);
        cout << endl;
    }
}