#include<iostream>
using namespace std;


void printArray(int arr[], int n){
    for(int i=0;i<n; i++){
        cout<<arr[i] << " ";
    }
    cout<<endl;
}





    void swapAlternate(int arr[],int size)
{
    for(int i=0; i <size; i+=2){
    if(i+1 <size)   { 
       //swap(arr[i], arr[i+1]);

       int temp= arr[i];
       arr[i]=arr[i+1];
       arr[i+1]= temp;
    }
    }
}

int main(){

int even[6]={1,2,3,4,5,6};
int odd[5]={1,2,3,4,5};


swapAlternate(even,6);
printArray(even,6);
cout<<endl;
swapAlternate(odd,5);
printArray(odd,5);


return 0;
}
