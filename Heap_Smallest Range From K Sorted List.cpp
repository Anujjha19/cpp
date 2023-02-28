#include <bits/stdc++.h>

class node
{
public:
    int data;
    int row;
    int col;

    node(int d, int r, int c)
    {
        data = d;
        row = r;
        col = c;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n)
{
    // Write your code here.
    int mini = INT_MAX;
    int  maxi = INT_MIN;
    priority_queue<node *, vector<node *>, compare> minHeap;

    // Step 1
    // create a min heap with start index  each list &
    // Keep track of min & max;

    for (int i = 0; i < k; i++)
    {
        int element = a[i][0];

        mini = min(mini, element);
        maxi = max(maxi, element);

        minHeap.push(new node(element, i, 0));
    }

    int start = mini;
    int end = maxi;

    // Step2
    // Range Process

    while (!minHeap.empty())
    {

        // MINi fetch
        node *temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        // Range Or ANs Updation
        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }

        // Check For Next Element
        if (temp->col + 1 < n)
        {
            maxi = max(maxi, a[temp->row][temp->col + 1]);
            minHeap.push(new node(a[temp->row][temp->col + 1], temp->row, temp->col + 1));
        }
        else
        {
            break;
        }
    }
    // Diff of range returning
    return (1 + end - start);
}