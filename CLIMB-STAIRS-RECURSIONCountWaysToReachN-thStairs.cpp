#include <iostream>
using namespace std;

int countDistinctWays(int nStairs)
{

    // Base Case
    if (nStairs < 0)
    {
        return 0;
    }
    if (nStairs == 0)
    {
        return 1;
    }

    // Recursive Relation
    int ans= countDistinctWays(nStairs-1) + countDistinctWays(nStairs-2);

    return ans;
}

int main()
{
    int nStairs;
    cin >> nStairs;

   int  value=countDistinctWays(nStairs);

cout << value;

    return 0;
}