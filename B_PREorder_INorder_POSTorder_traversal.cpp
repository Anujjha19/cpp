#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildTree(node *root)
{

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

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

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child ndoes
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

void inOrder(node *root)
{

    // base case
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void preOrder(node *root)
{

    // base case
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node *root)
{

    // base case
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{

    node *root = NULL;
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    // creating a Tree
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // level order
    cout << "Printing the level order traversal output " << endl;
    levelOrderTraversal(root);

    cout << "InOrder Traversal Is : " << endl;
    inOrder(root);
    cout << endl;

    cout << "PreOrder Traversal Is : " << endl;
    preOrder(root);
    cout << endl;

    cout << "PostOrder Traversal Is : " << endl;
    postOrder(root);

    return 0;
}

/* Iterative Pre-Order
vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root ==NULL ) return ans;

        stack<TreeNode*>s;
        s.push(root);
        while( !s.empty()){
            root = s.top();
            s.pop();
            ans.push_back( root -> val);
            if( root -> right != NULL){
                s.push(root->right);
            }
            if( root -> left != NULL){
                s.push(root->left);
            }
        }
        return ans;

    }
 */

/* Iterative In-Order

vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* node =root;
        if(root == NULL) return ans;

        stack<TreeNode*> s;
        while(true){

        if( node != NULL){
            s.push(node);
            node = node -> left;
        }else{
            if(s.empty()  == true ) break;
            node = s.top();
            s.pop();
            ans.push_back(node->val);
            node =node ->right;
        }

        }
        return ans;
    }

*/
/* Iterative Post-Order

vector<int> postorderTraversal(TreeNode* root) {
        vector <int> ans;
        if(root ==NULL) return ans;
        stack<TreeNode* > s;
        while( root !=NULL ||  !s.empty()){
            if( root !=NULL){
                s.push(root);
                root = root -> left;
            }
            else{
                TreeNode* temp= s.top() -> right;
                if(temp==NULL){
                    temp=s.top();
                    s.pop();
                    ans.push_back(temp -> val);

                    while(!s.empty() && temp == s.top() -> right ){
                                temp = s.top();
                    s.pop();
                    ans.push_back(temp -> val);
                    }
                }
                else root = temp;
            }
        }
        return ans;
    }

*/