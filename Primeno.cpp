#include<iostream>
using namespace std;
/* int main(){
    int n;
    cin>>n;

    int i=2;
    while (i< n)
    {
       if(n%i==0){
        cout<<"Not Prime"<< endl;
return 0;
       }
       i=i+1;
    }
    cout<<"Prime No"<<endl;
    
} */

bool isPrime(int n)
{

    for(int i=2; i<n ; i++){
        if(n%i == 0){
            return 0;
        }
    }
return 1;



}
int main(){
    int n;
    cin >> n;

    if(isPrime(n)){
        cout<<"is a prime no" << endl;
        
    }
    {
        cout<<"is not a prime no" << endl;

    }
}