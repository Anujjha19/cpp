#include<iostream>
using namespace std;

int main()
{
/*
    int n;
    cout<<"Number is :";
    cin >> n ;
int sum =0;
    int i= 0;
    while( i <= n){
       sum = sum + i;
       i = i + 1;
    
    }
    cout << "Sum from  0 to " << n << " = " << sum <<endl;
return 0;

int main(){
    int n;
    cout<<"Number is :";
    cin >> n ;
int sum =0;
    int i= 2;
    while( i <= n){
        if (i % 2 ==0 )
       sum = sum + i;
       i = i + 1;
    
    }
    cout << "Sum from  0 to " << n << " = " << sum <<endl;
return 0;



float fahrenheit;
cin>> fahrenheit;
float clesius = (5.0/9)* (fahrenheit-32);
cout << fahrenheit << "F ="<< clesius << "C"<< endl;
return 0;

*/
 int n; 
 cin >> n;
 int i =2;
 while ( i < n )
{
    if (n % i == 0){
        cout<< "not prime" << endl;
        return 0;
    }
    i = i+1 ;
}
cout<< " Prime "<< endl;
return 0;
}