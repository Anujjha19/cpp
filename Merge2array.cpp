#include<iostream>
using namespace std;

int move0(int arr[], int brr[], int m, int n){
    int p1=m-1, p2=n-1, i=m+n-1;
    while(p2>=0){
        if(p1>=0 && arr[p1] > brr[p2]){
            arr[i]=arr[p1];
            i--;
            p1--;       
        }
        else{
            arr[i--]=brr[p2--];
        }
    }
}

void printArray(int arr[] , int m){
    for(int i=0; i< m; i++){
        cout<<arr[i] << " ";
    }      
    cout<<endl;

}


int main(){

    int arr[3]={2,6,10};
    int brr[3]={1,5,11};
  


       move0(arr,brr , 3 , 3);

    printArray( arr,6);
   

    return 0;

}