#include<iostream>
using namespace std;


void print(int arr[], int size) {
    cout << "Size of array is " << size << endl;

    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    } cout << endl;

}

bool linearSearch(int arr[], int size, int k ) {

print(arr,size);

//Base Case
if(size==0){
    return 0;
}
if(arr[0]== k){
    return 1;
}
else{
    bool  remainingCheck=linearSearch(arr+1, size-1, k);
return remainingCheck;
}
}
int main(){

    int arr[5]={3,5,1,2,6};
    int size=5;
    int key=6;
    bool ans= linearSearch(arr , size , key);
    if(ans ){
        cout << "Key is Present " << endl;
    }
    else{
        cout << " Key is absent " << endl;
    }

return 0;
}