#include<iostream>
using namespace std;

bool search(int arr[], int size, int key){

    for(int i=0; i<size; i++){

        if(arr[i]==key){
            return 1;
        }
    }
    return 0;
}


int main(){

int arr[10]={ 5, 2, -7, -8, 6, 4, 3, 7, 0, 1};
cout<<"The key is "<< endl;
int key;
cin>>key;

bool found=search(arr , 10, key);
    if(found){
        cout<<"Key is Present"<<endl;

    }
    else{

         cout<<"Key is Absent"<<endl;

    }
}


