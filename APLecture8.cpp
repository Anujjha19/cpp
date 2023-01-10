#include<iostream>
using namespace std;

/* 
int AP(int n){

    int ap = n*3+7;
    return ap;

}

int main()
{
  int n;
  cin>>n;
  int ans=AP(n);
  cout<<"Answer is="<<ans<<endl;

  return 0;
}  */


/* int SetbitA(int a){
    int count =0;
    while (a!=0){
        if(a&1){
            count++;
        }
        a=a>>1;

    }
    return count;
    
}

int SetbitB(int b){
    int count =0;
    while (b!=0){
        if(b&1){
            count++;
        }
        b=b>>1;

    }
    return count;
    
}
int main(){ 
    int a , b;
    cin >> a  >>b;
    int ans1=SetbitA(a);
    int ans2=SetbitB(b);
   
    
    cout<<"ans of a:" << ans1;
    cout<<endl;
    cout<<"ans of b:" << ans2;
    cout<<endl;

    int ans = ans1+ ans2;
    cout<< "Total bit" << ans << endl;

    return 0;

    



} */

int fibonaccci(int n){
    int a=0;
    int b=1;
    
    for(int i=2; i <n; i++){

        int next = a+b;
        a=b;
        b= next;
    }
    return b;
}
int main(){
    int n;
    cin>> n;
    cout<<"The nth term is " << fibonaccci(n)<< endl;

return 0;
}

































