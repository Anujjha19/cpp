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
    

    while (!q.empty())
    {
        int count = q.size();
        for(int i=0; i<count ;i++){
            node *curr = q.front();
            q.pop();
            cout << curr -> data << " " ;
            if(curr -> left !=NULL ) q.push(curr -> left);
            if(curr -> right !=NULL ) q.push(curr -> right);
        }
        cout << endl ;
    }
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

    return 0;
}