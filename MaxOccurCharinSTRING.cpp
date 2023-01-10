#include<iostream> 
using namespace std;
/* char toLowerCase(char ch) {
    if(ch >='a' && ch <='z')
        return ch;
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
} */

char getMaxOccCharacter(string s){

  
    int arr[26]={0};
    //create an array count of characters
    for(int i=0; i<s.length(); i++){
        char ch=s[i];
        
        int number=0;
        number=ch-'a';
        arr[number]++;
    }
    //Find max occ character
  int maxi = -1, ans = 0;
    for(int i=0;i<26; i++) {
        if(maxi < arr[i]) {
            ans = i;
            maxi = arr[i];
        }
}
return 'a'+ans; // final ans

}


int main( ) {
/*
    char name[20];
    cout << "Enter your name " << endl;
    cin >> name;
    //name[2] = '\0';
    cout << "Your name is ";
    cout << name << endl;
    int len = getLength(name);
    cout << " Length: " << len << endl;
    reverse(name, len);
    cout << "Your name is ";
    cout << name << endl;
    cout <<" Palindrome or Not: " << checkPalindrome(name, len) << endl;
    cout << " CHARACTER is " << toLowerCase('b') << endl;
    cout << " CHARACTER is " << toLowerCase('C') << endl;
    */

    string s;
    cin >> s;

    cout << getMaxOccCharacter(s) << endl;

    return 0;
    // tc O(n)
    //sc O(1)
}