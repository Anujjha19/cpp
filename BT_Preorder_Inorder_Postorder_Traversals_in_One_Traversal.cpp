#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

vector<int>  allTraversal(node *root, vector<int> &pre, vector<int> &in, vector<int> &post)
{
    stack<pair <node* , int >> s;
    s.push({root , 1});
    vector<int>pre, in, post;
    if(root==NULL) return oot ;

    while(!s.empty()){
        auto it = s.top();
        s.pop();
    
    //This is Pre , increment 1 to 2 , push the left side of tree

    if(it.second ==1){
        pre.push_back(it.first -> data);
        it.second++;
        s.push(it);

        if(it.first -> left != NULL ){
            s.push({it.first-> left , 1});
        }
    }
        //This is In , increment 2 to 3 , push the right side of tree

    if(it.second ==2){
        in.push_back(it.first -> data);
        it.second++;
        s.push(it);

        if(it.first -> right != NULL ){
            s.push({it.first-> right , 1});
        }
    }
    else{
        post.push_back(it.first-> data);
    }
    }


}

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int main()
{

    struct node *root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    vector<int> pre, in, post;
    allTraversal(root, pre, in, post);

    cout << "The preorder Traversal is : ";
    for (auto nodeVal : pre)
    {
        cout << nodeVal << " ";
    }
    cout << endl;
    cout << "The inorder Traversal is : ";
    for (auto nodeVal : in)
    {
        cout << nodeVal << " ";
    }
    cout << endl;
    cout << "The postorder Traversal is : ";
    for (auto nodeVal : post)
    {
        cout << nodeVal << " ";
    }
    cout << endl;

    return 0;
}
