#include<iostream>
using namespace std;

void reverse(char name[], int n){

    int s=0;
    int e=n-1;
    while(s<e){
        swap(name[s++], name[e--]);
    }
}
int getlength(char name[]){
int count=0;
    for(int i=0; name[i] != '\0'; i++){
count++;
    }
    return count;
}
int main(){
    
    char name[20];
    cout<< "Enter Name" << endl;
    cin >> name;
    // name[2] ='\0';


    cout<< "name is :";
    cout << name << endl;
    int len=getlength(name);


reverse(name , len);
    cout<< "Length "<< getlength(name)<<endl;
    cout<< " Reverse name is :";
    cout << name << endl;
    
    return 0;
}