//Breadth First Search

int maxDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ln = maxDepth(root->left);
    int rn = maxDepth(root->right);

    if (ln < rn)
    {
        return (rn + 1);
    }
    else
    {
        return (ln + 1);
    }
} 

//Depth First Search
/* 
int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int count = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        ++count;
        for (int i = 0, n = q.size(); i < n; ++i)
        {
            TreeNode *p = q.front();
            q.pop();

            if (p->left != NULL)
                q.push(p->left);
            if (p->right != NULL)
                q.push(p->right);
        }
    }

    return count;
} */

