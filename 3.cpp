#include<iostream>
using namespace std;
int main(){
    char a;
    cout<<" Char Ch is :" << endl;
    cin >>a ;
    if (a>='A' && a<='Z'){
        cout << "This is UppeR Case" <<endl;
    }else if (a>='a' && a<='z'){
        cout << "This is LoweR Case" <<endl;
    
    } else if ( a>='0' && a<= '9'){
        cout<< "This is NumerIc" <<endl;
    }

return 0;

}