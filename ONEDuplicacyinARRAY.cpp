#include<iostream>
using namespace std;

/* int printAnswer(arr[], int size){
     int ans=0;
    for(int i=0; i<size; i++){
        ans=ans^arr[i];
    }
    return ans;
}  */

int main()
{

    int size;
    cin>>size;
    int arr[100];
    for(int i=0; i<size; i++){
        cin>> arr[i];
    }

 int ans=0;
    for(int i=0; i<size; i++){
        ans=ans^arr[i];
    }
   

    for(int i=1; i<size; i++){
        ans=ans^i;
    }


   // return ans; 
    cout<<"Unique Element is:" << ans; 
cout<<endl;
}