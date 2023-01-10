#include <iostream>
using namespace std;

int power(int a , int b){
    //Base case
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    //Recursion call
    int ans = power(a , b/2);
    //b is even
    if(b%2==0){
        return ans* ans;
    }
    else{
        // b is odd
        return a* ans * ans;
    }
}


int main()
{
int a , b;
cout<<"Enter a :"<<endl;
cin >>a;
cout<<"Enter b :"<<endl;
cin >>b;
cout<<endl;
int ans =power(a,b);
cout << "Power of " << a << " , " <<b <<": " << ans << endl;


    return 0;
}
