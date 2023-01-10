#include<iostream>
using namespace std;

bool isPrime(int n) {

    if(n<=1)
    return false; // (Base Case)

    for(int i=2; i<n; i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

int main() {

    int n;
    cin >> n;

    if(isPrime(n)) {
        cout << "It is a Prime Number" << endl;
    }
    else{
        cout << " It is not a Prime Number" << endl;
    }


    return 0;
}
// TC = O(n-2)= O(n)
// Sc = O(1)