#include<iostream>
#include<math.h>
using namespace std;
int main(){

  // /*
    int n;
    cin >> n;
    int answer = 0;
    int i = 0 ;
  
  while (n != 0){

        int bit = n & 1;
        answer  = ( bit * pow (10 , i) )+ answer;

        n= n >> 1;
        i++;

  }

  cout<< " answer is " << answer << endl;
// */

   /* 
    int n;
    cin >> n;
    int answer = 0;
    int i = 0 ;
  
  while (n != 0){

      //  int digit = n % 10 ;
      //  answer  = ( answer * 10 )+ digit;

      int digit = n% 10;
      answer = ( digit * pow (10 , i)) + answer;
      
      n = n /10;
      i++;

  }

  cout<< " answer is " << answer << endl;

*/
} 
