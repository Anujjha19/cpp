#include <iostream>
using namespace std;
#include <queue>
#include <map>
#include<unordered_map>


string FirstNonRepeating(string A)
{
    // Code here
    unordered_map<char, int> count;
    queue<int> q;
    string ans = "";
        
    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];

        // Increased Count
        count[ch]++;

        // Queue mai Push
        q.push(ch);

        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                // Repeating character
                q.pop();
            }
            else
            {
                // non repeating character
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}