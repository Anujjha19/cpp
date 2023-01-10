/* #include<iostream>
using namespace std;


void reverse(string& str , int i , int j)
{
    cout << "Given String : " << str <<endl;
    
    // base case
    if(i>j){
        return;
    }
    swap(str[i], str[j]);
    i++;
    j--;
    // recursive call
    reverse(str , i ,j);
}


int main(){
    
    string name = "anuj";
    cout<<endl;
    reverse(name ,0,name.length()-1 );
    cout<<endl;

cout << "Reverse String :" << name << endl;
return 0;

} */
 #include<iostream>
using namespace std;


void reverse(string& str , int i )
{
    //cout << "Given String : " << str <<endl;
    
    // base case
    if(i>(str.length() - 1 - i)){
        return;
    }
    swap(str[i], str[(str.length() - 1 - i)]);
    i++;
    
    // recursive call
    reverse(str , i);
}


int main(){
    
   
string name = "geeksforgeeks";
int x= name.length();
cout << x;
 
    reverse(name, 0);
    cout << name << endl;
    return 0;
} 

