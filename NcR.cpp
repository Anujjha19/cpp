#include<iostream>
using namespace std;

int factorial(int n){

    int fact=1;

    for(int i=1; i <=n; i++){
        fact=fact * i;

    }
    return fact;
}
int nCr(int n , int r){

int num= factorial (n);
int denom=factorial(r) * factorial(n-r);

return num/denom;



}


int main( ){
 int n , r;
 cin>> n >> r ;


cout<<"answer is " << nCr(n,r);
    return 0;
}

/* #include<iostream>
using namespace std;

void PrintCounting(int n){

    for(int i=1; i <=n ; i++){
        cout<< i <<" " ;

    }
    cout<< endl;
}
int main(){

    int n;
    cin >> n;

    PrintCounting(n);
} */