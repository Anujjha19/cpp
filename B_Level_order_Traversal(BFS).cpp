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

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
}
int main() {

    node* root = NULL;
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    //creating a Tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    //level order
    cout << "Printing the level order traversal output " << endl;
    levelOrderTraversal(root);


    return 0;
}
/* 
  vector<vector<int>> levelOrder(TreeNode* root) {

            vector<vector<int>> ans;
            if( root ==NULL) return ans;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                int size= q.size();
                vector<int> level ;
                for(int i=0; i< size; i++){
                    TreeNode *node = q.front();
                    q.pop();
                    if( node-> left != NULL`)q.push(node-> left);
                    if(node -> right != NULL) q.push(node -> right);

                    level.push_back(node-> val);
                }
ans.push_back(level);
            }
                    return ans;

        } */

 /*        vector<int> levelOrder(Node* node)
   {   
       Node* temp;
       queue<Node*>q;
       vector<int>v;
       q.push(node);
       while(!q.empty()){
           temp=q.front();
           q.pop();
           v.push_back(temp->data);
           if(temp->left) q.push(temp->left);
           if(temp->right) q.push(temp->right);
       }
   return v;
   }

 */