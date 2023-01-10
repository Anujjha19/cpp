#include <iostream>
using namespace std;
int fibonacciNo(int n)
{
    //Base Case

    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }

    int ans =fibonacciNo(n-1)+ fibonacciNo(n-2);
    return ans;



}

int main()
{
    int n;
    cout << "Input is :" ;
    cin >> n;
    cout << endl;

  int result=  fibonacciNo(n);
  cout<< result;

    return 0;
}

/* #include <iostream>
using namespace std;

int main() {
    int n, t1 = 0, t2 = 1, nextTerm = 0;

    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonacci Series: ";

    for (int i = 1; i <= n; ++i) {
        // Prints the first two terms.
        if(i == 1) {
            cout << t1 << ", ";
            continue;
        }
        if(i == 2) {
            cout << t2 << ", ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        
        cout << nextTerm << ", ";
    }
    return 0;
}
Enter the number of terms: 10
Fibonacci Series: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 
 */

/* #include <iostream>
using namespace std;

int main() {
    int t1 = 0, t2 = 1, nextTerm = 0, n;

    cout << "Enter a positive number: ";
    cin >> n;

    // displays the first two terms which is always 0 and 1
    cout << "Fibonacci Series: " << t1 << ", " << t2 << ", ";

    nextTerm = t1 + t2;

    while(nextTerm <= n) {
        cout << nextTerm << ", ";
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }
    return 0;
}
Enter a positive integer: 100
Fibonacci Series: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 

 */

/* #include<iostream>
using namespace std;
int fib(int n) {
   if (n <= 1)
   return n;
   return fib(n-1) + fib(n-2);
}
int main () {
   int n = 10, i;
   for(i=0;i<n;i++)
   cout<<fib(i)<<" ";
   return 0;
}

Output
0 1 1 2 3 5 8 13 21 34 */
