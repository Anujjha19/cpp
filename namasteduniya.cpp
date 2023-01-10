#include<iostream>

#include<math.h>
using namespace std;
int main(){

   // cout<<"Namaste Duniya" << endl;

        int n;
    cin >> n;
    int answer = 0;
    int i = 0 ;
  
  while (n != 0){

      //  int digit = n % 10 ;
      //  answer  = ( answer * 10 )+ digit;

      int digit = n% 10;
      answer = ( digit * pow (10 , i)) + answer;
      
      

  }

  cout<< " answer is " << answer << endl;

}