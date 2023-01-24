pair<bool, int> fastSum(Node *root)
{

    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftPart = fastSum(root->left);
    pair<bool, int> rightPart = fastSum(root->right);

    bool left = leftPart.first;
    bool right = rightPart.first;

    bool checkSum = root->data == leftPart.second + rightPart.second;

    pair<bool, int> ans;
    if (left && right && checkSum)
    {
        ans.first = true;
        ans.second = 2 * root->data;
        // leftPart -> data + rightPart -> data + root->data;
    }
    else
    {
        ans.first = false;
        ans.second = 2 * root->data;
    }

    return ans;
}

bool isSumTree(Node *root)
{
    fastSum(root).first;
}