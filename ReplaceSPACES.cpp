// WITH Extra Space
#include<iostream> 
using namespace std;

string replaceSpaces(string &str){
    string temp="";
    for(int i=0; i<str.length(); i++){
        if(str[i]==' '){
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else{
            temp.push_back(str[i]);
        }
    }
    return temp;
}


int main( ) {

    string str;
    getline(cin, str);

    cout << replaceSpaces(str) << endl;

    return 0;
    
}
/* 
// WITHOut Extra space 


#include<iostream> 
using namespace std;

string replaceSpaces(string &str){
      for(int i=0;i<str.length();i++)  

  {     

       if(str[i]==' ')     

       {       

             int i=str.find(' ');        

             str.replace(i,1,"@40");    

        }   

    }    

     return str; 

 }
/*  
 string replaceSpaces(string &str){

   

   for(int i=0; i<str.length(); i++){

       if(str[i]==' '){

           str.erase(i, 1); //method 2
           str.insert(i, "@40");

       }

   }

   return str;

} */


/* 
int main( ) {

    string str;
    getline(cin, str);

    cout << replaceSpaces(str) << endl; 

    return 0;
    
} */ 