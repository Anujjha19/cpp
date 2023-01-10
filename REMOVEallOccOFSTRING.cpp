

#include<iostream> 
using namespace std;
int removePARTocc(string &str , string &part){

while(str.length()!=0 && str.find(part) < str.length()){
    str.erase(str.find(part) , part.length());
}

    return str;

}
int main( ) {
cout<< "str :"<<endl;
    string str;
    getline(cin, str);

cout<< "part :"<<endl;
    string part ;
    getline(cin, str);

    cout << removePARTocc(str , part) << endl;

    return 0;
    
}