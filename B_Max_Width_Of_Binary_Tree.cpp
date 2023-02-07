#include <iostream>
#include <queue>
#include <map>
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
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

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

int widthOfTree(Node *root)
{
    if (!root)
        return 0;

    queue<pair<Node *, int>> q;
    q.push({root, 0});
    int ans = 0;

    int mmin = q.front().second;
    int last, first;

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int currId = q.front().second - mmin;
            Node *node = q.front().first;
            q.pop();
            if (i == 0)
                first = currId;
            if (i == size - 1)
                last = currId;

            if (node->left != NULL)
                q.push({node->left, currId * 2 + 1});
            if (node->right != NULL)
                q.push({node->right, currId * 2 + 2});
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}
int main()
{

    Node *root = NULL;
    root = buildTree(root);

    int ans = widthOfTree(root);

    cout << "Max Width of Tree : " << ans << endl;

    return 0;
}
