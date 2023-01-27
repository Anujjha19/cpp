vector<int> topView(Node *root)
{
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }

    // HD , nodes
    map<int, int> m;
    // Node* and HD
    queue<pair<Node *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();

        Node *node = temp.first;
        int line = temp.second;

        // 1 to map , if 1 value is present for 1 HD do nothing
        // if one value is present for a HD, then do nothing
        if (m.find(line) == m.end())
        {
            m[line] = node->data;
        }

        if (node->left)
        {
            q.push({node->left, line - 1});
        }
        if (node->right)
        {
            q.push({node->right, line + 1});
        }
    }

    for (auto it : m)
    {
        ans.push_back(it.second);
    }

    return ans;
}