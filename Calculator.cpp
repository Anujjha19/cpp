#include<iostream>
// #include<cmath>
using namespace std;
int main()
{
    
    int a, b;
    cout<<"value of a :" <<endl;
    cin>>a;
     cout<<"value of b :"<<endl;
    cin>>b;
char op;
cout<<"Operation"<< endl;
cin>>op;

switch(op){

    case '+': cout<<(a+b) <<endl;
    break;
    case '-': cout<<(a-b) <<endl;
        break;

    case '*': cout<<(a*b) <<endl;
        break;

    case '/': cout<<(a/b) <<endl;
        break;

    case '%': cout<<(a%b) <<endl;
        break;



}


} // namespace std;

