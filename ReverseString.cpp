#include<iostream>
#include<string>
using namespace std;

void reverse(char string[], int n){

    int s=0;
    int e=n-1;
    while(s<e){
        swap(string[s++], string[e--]);
    }
}


int main(){
    
    char string[]={'a', 'b', 'c', 'd','e'};
    

    cout<< "string is :";
    cout << string << endl;
    
reverse(string , 5);
    
    cout<< " Reverse string is :";
    cout << string << endl;
    

    return 0;
}
/* 
T.C = O(n)
S.C = O(1) */