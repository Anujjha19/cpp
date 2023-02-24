#include <bits/stdc++.h>
using namespace std;
#define n 4

class node
{
public:
    int data;
    int i;
    int j;

    node(int d, int row, int col)
    {
        this->data = d;
        i = row;
        j = col;
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

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k, vector<int> &ans)
{
    priority_queue<node *, vector<node *>, compare> minHeap;

    for (int i = 0; i < k; i++)
    {
        node *temp = new node(kArrays[i][0], i, 0);

        minHeap.push(temp);
    }
    while (!minHeap.empty())
    {

        node *tempTopElem = minHeap.top();

        ans.push_back(tempTopElem->data);
        minHeap.pop();

        int i = tempTopElem->i;
        int j = tempTopElem->j;

        if (j + 1 < kArrays[i].size())
        {
            node *next = new node(kArrays[i][j + 1], i, j + 1);
            minHeap.push(next);
        }
    }
    return ans;
}

int main()
{
    // Changing the number of elements in an array
    int arr[][n] = {{2, 6, 12, 34},
                    {1, 9, 20, 1000},
                    {23, 34, 90, 2000}};
    int k = sizeof(arr) / sizeof(arr[0]);

    vector<vector<int>> inVec(arr, arr + n);

    vector<int> ans;

    mergeKSortedArrays(inVec, 3, ans);

    cout << "Merged array is " << endl;

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}
