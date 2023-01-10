#include<iostream>
using namespace std;

void move0(int arr[], int n){


    int i=0;
    for(int j=0; j<n; j++){
        if(arr[j]!=0){
            swap(arr[j],arr[i]);
            i++;
        }
    }

}

void printArray(int arr[] , int n){

    for(int i=0; i< n; i++){
        cout<<arr[i] << " ";
    }      
    cout<<endl;

}


int main(){

    int arr[6]={0,5,0,6,0,-5};
  


       move0(arr,6);

    printArray( arr,6);
   

    return 0;

}