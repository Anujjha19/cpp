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

Node *createMapping(Node *root, int target, map<Node *, Node *> &nodeToParent)
{

    Node *res = NULL;

    queue<Node *> q;

    q.push(root);
    nodeToParent[root] = NULL;

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front->data == target)
        {
            res = front;
        }
        if (front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

int burnTree(Node *root, map<Node *, Node *> &nodeToParent)
{
    map<Node *, bool> visited;

    queue<Node *> q;
    q.push(root);
    visited[root] = true;
    int ansTime = 0;

    while (!q.empty())
    {
        bool flag = 0;

        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            // Process Neighbouring Nodes
            Node *front = q.front();
            q.pop();

            if (front->left && !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }

            if (front->right && !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }

            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
            }
        }
        if (flag == 1)
        {
            ansTime++;
        }
    }

    return ansTime;
}

int minTime(Node *root, int target)
{

    map<Node *, Node *> nodeToParent;
    Node *targetNode = createMapping(root, target, nodeToParent);

    int ans = burnTree(targetNode, nodeToParent);
    return ans;
}



int main()
{

    Node *root = NULL;
    root = buildTree(root);

    int target;
    cin >> target;

    cout << "Target Node " << target << endl;

    int ans = minTime(root, target);

    cout << "Min Time TO Burn :  " << ans;

    return 0;
}
