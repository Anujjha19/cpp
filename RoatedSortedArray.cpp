#include<iostream>
using namespace std;

bool check(int arr[], int n){
    int count =0;
    for(int i=1; i<n; i++){
        if(arr[i-1]>arr[i]){
            count++;
        }
    }
    if(arr[n-1]>arr[0]){ 
    count++;
}/* 
if(count<=1){
    return true;

}
else{
    return false;
} */
return count<= 1;

}




/* void printArray(int arr[] , int n){

    for(int i=0; i< n; i++){
        cout<<arr[i] << " ";
    }      
    cout<<endl;

} */


int main(){

    int arr[5]={3,4,5,1,2};
   

//    check(arr,5);
      cout<<check(arr,5);
    // printArray( arr,5);  

  //  return 0;

} 
