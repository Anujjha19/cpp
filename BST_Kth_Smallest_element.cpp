

#include <bits/stdc++.h>
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
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left)
        inorder(root->left);
    cout << root->data << " ";
    if (root->right)
        inorder(root->right);
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // Current level is complete, print a new line
            cout << endl;
            if (!q.empty())
            {
                // Queue still has some child nodes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

Node *insertIntoBST(Node *root, int d)
{
    // Make first node in the BST
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

vector<int> ans;
Node *inorder1(Node *root)
{
    if (root == NULL)
        return root;

    if (root->left)
        inorder(root->left);
    ans.push_back(root->data);
    if (root->right)
        inorder(root->right);

    return root;
}
int kthSmallest(Node *root, int k)
{
    inorder1(root);
    return ans[k - 1];
}




int main()
{
    Node *root = NULL;

    cout << "Enter data to make a BST (end with -1): " << endl;
    takeInput(root);

    cout << "Printing BST: " << endl;
    levelOrderTraversal(root);

    int k ;
    cin>>k;

    int ans = kthSmallest( root , k);
    cout << ans;

    return 0;
}



/*

int kthSmallest(TreeNode* root, int k) {

        TreeNode*current,*pre;
        if (root==NULL)
            return 0;
        current=root;
        int count=0,ans;
        while (current!=NULL)
        {
            if (current->left==NULL)
            {
                count+=1;
                if (count==k)
                    ans=current->val;
                current=current->right;
            }
            else
            {
                pre=current->left;
                //Finding the inorder predecessor of the current node-rightmost node of current's left subtree.
                while (pre->right!=NULL && pre->right!=current)
                    pre=pre->right;
                //making the right pointer of inorder predecessor to point to current.
                if (pre->right==NULL)
                {
                    pre->right=current;
                    current=current->left;
                }
                else
                {
                    pre->right=NULL;
                    count+=1;
                    if (count==k)
                        ans=current->val;
                    current=current->right;
                }

            }
        }
        return ans;
    }
 */