class Solution
{

private:
    TreeNode *first;
    TreeNode *last;
    TreeNode *prev;
    TreeNode *middle;

private:
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        if (prev != NULL && root->val < prev->val)
        {
            // First Wrong Node;
            if (first == NULL)
            {
                first = prev;
                middle = root;
            }
            // Second Wrong Node
            else
            {
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        first = last = middle = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if (last && first)
            swap(last->val, first->val);
        else
        {
            swap(first->val, middle->val);
        }
    }
};