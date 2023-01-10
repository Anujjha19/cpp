#include <iostream>
#include <queue>
using namespace std;
int main()
{

    queue<int> q;
    q.push(5);

    cout << "Front : " << q.front() << endl;
    cout << "Rear : " << q.back() << endl;

    q.push(7);
    cout << "Front : " << q.front() << endl;
    cout << "Rear : " << q.back() << endl;
    q.push(10);
    cout << "Front : " << q.front() << endl;
    cout << "Rear : " << q.back() << endl;
    cout << "Size of Queue : " << q.size() << endl;

    q.pop();
    cout << "Size of Queue : " << q.size() << endl;

    if (q.empty())
    {
        cout << "Queue is Empty.";
    }
    else
    {
        cout << "Queue is Not Empty.";
    }
}