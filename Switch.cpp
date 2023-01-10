#include<iostream>
#include <stdlib.h>
using namespace std;
int main()
{

//this while condition will always be true if exit( is not put.)
while(1)
{
  cout<<"HOW YOU DOIN????"<<endl;

  int num=1;
  switch(num)
  {
    case 1: cout<<"I'M FINE"<<endl;
    continue;
  }
  exit(0);
}

}