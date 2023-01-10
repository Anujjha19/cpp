/* #include<iostream>
#include<string>
using namespace std;
bool checkPalindrome(char string[], int n){
    int s=0;
    int e=n-1;
    while(s<e){
        if(string[s] != string[e])
        return 0;
        else{
            s++; 
            e--;
        }
    }
    return 1;
}

void reverse(char string[], int n){

    int s=0;
    int e=n-1;
    while(s<e){
        swap(string[s++], string[e--]);
    }
}


int main(){
    
    char string[5];

    cin>> string;
    

    cout<< "string is :";
    cout << string << endl;
    
reverse(string , 5);
    
    cout<< " Reverse string is :";
    cout << string << endl;

    cout<< "Palindrome Or not  " << checkPalindrome(string, 5) << endl;
    

    return 0;

} 
Case Sensitive 
Noon Palindrome 0
*/
/* 
Not Case Sensitive 
Noon Palindrome 1 */
#include<iostream>
#include<string>
using namespace std;

char toLowerCase(char ch){
    if(ch >='a' && ch <='z')
    return ch;
    else{
        char temp=ch-'A' +'a';
        return temp;
    }
}
bool checkPalindrome(char string[], int n){
    int s=0;
    int e=n-1;
    while(s<=e){
        if(toLowerCase(string[s]) != toLowerCase(string[e]))
        return 0;
        else{
            s++; 
            e--;
        }
    }
    return 1;
}

void reverse(char string[], int n){

    int s=0;
    int e=n-1;
    while(s<e){
        swap(string[s++], string[e--]);
    }
}


int main(){
    
    char string[5];

    cin>> string;
    

    cout<< "string is :";
    cout << string << endl;
    
reverse(string , 5);
    
    cout<< " Reverse string is :";
    cout << string << endl;

    cout<< "Palindrome Or not  " << checkPalindrome(string, 5) << endl;
    

    return 0;
}