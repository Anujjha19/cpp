#include <iostream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";

        string s = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *curNode = q.front();
            q.pop();
            if (curNode == NULL)
                s.append("#,");
            else
                s.append(to_string(curNode->val) + ',');
            if (curNode != NULL)
            {
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;

        // Will Take the Data and make it as  Object
        stringstream s(data);
        string str;
        // Take first object and store it at the str
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {

            TreeNode *node = q.front();
            q.pop();

            getline(s, str, ',');
            if (str == "#")
            {
                node->left = NULL;
            }
            else
            {
                TreeNode *leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if (str == "#")
            {
                node->right = NULL;
            }
            else
            {
                TreeNode *rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

int main()
{
    Solution Solution;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string data = Solution.serialize(root);
    cout << "Serialized tree: " << data << endl;

    TreeNode *newRoot = Solution.deserialize(data);
    cout << "Deserialized tree: " << newRoot->val << endl;

    return 0;
}
