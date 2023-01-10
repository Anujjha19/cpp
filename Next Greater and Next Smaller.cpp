/* //APPROACH 1
#include <iostream>
using namespace std;
void NextGreater(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                temp = arr[j];
                cout << temp << " ";
                break;
            }
        }
        if (temp == -1)
        {
            cout << temp << " ";
        }
    }
}
void NextSmaller(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                temp = arr[j];
                cout << temp << " ";
                break;
            }
        }
        if (temp == -1)
        {
            cout << temp << " ";
        }
    }
}
int main()
{
    int arr[] = {2, 13, 10, 6, 3, 9};
    cout << "Next Greater Element are" << endl;
    NextGreater(arr, 6);
    cout << endl;
    cout << "Next Smaller Element are" << endl;
    NextSmaller(arr, 6);
}
 */

//APPROACH 2
#include <bits/stdc++.h>

vector<int> findNextGreaterElements(vector<int> &arr)
{

    int n = arr.size();
    vector<int> answer(n, -1) // creates the answer array

        stack<int>
            s;                  // creating an empty stack
    for (int i = 0; i < n; i++) // traversing through the elements in the array
    {
        while (!s.empty() && arr[s.top()] < arr[i]) // finds next greater element
        {
            answer[s.pop()] = arr[i];
        }
        s.push(i);
    }
    return answer;
}

// Method to find the next smaller element for every array element
vector<int> findNextSmallerElements(vector<int> &arr)
{
    int n = arr.size();
    vector<int> answer(n, -1); // creates the final array

    stack<int> s;               // creating an empty stack
    for (int i = 0; i < n; i++) // traversing through the elements in the array
    {
        while (!s.empty() && arr[s.top()] > arr[i]) // finds next smaller element
        {
            answer[s.pop()] = arr[i];
        }
        s.push(i);
    }
    return answer;
}

int main()
{
    int n, x;
    cin >> n;
    vector<int> input;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        input.push_back(x);
    }
    vector<int> result = findNextGreaterElements(input);
    cout << "Next Greater Elements are" << endl;
    for (auto a : result)
    {
        cout << a << " ";
    }
    cout << endl;
    result = findNextSmallerElements(input);
    cout << "Next Greater Elements are" << endl;
    for (auto a : result)
    {
        cout << a << " ";
    }
}
