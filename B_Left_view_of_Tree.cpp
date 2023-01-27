
void solve(Node *root, vector<int> &ans, int level)
{
    // BaseCase
    if (root == NULL)
    {
        return;
    }

    // TO check new level  - [ we entered into a new level ]

    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}

vector<int> leftView(Node *root)
{

    vector<int> ans;
    solve(root, ans, 0);

    return ans;
}
/* void solve(Node *root, vector<int> &ans, int level)
{
    // BaseCase
    if (root == NULL) { return; }
    if( maxLevel < level ){
        cout<< (root -> data ) << endl;
        maxLevel = level;
    }
    solve(root->left,  level + 1);
    solve(root->right,  level + 1);
}
int maxLevel=0;
vector<int> leftView(Node *root)
{
    solve(root, 1);
}
*/