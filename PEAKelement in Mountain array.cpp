#include<iostream>
using namespace std;

int Peakelement(int arr[], int size, int key){
    

    int s=0; 
    int e=size-1;
    int mid = s + (e-s)/2;

    while(s<e){
        if(arr[mid] < arr[mid+1] ){
            s=mid-1;

        }
        else {
            // arr[mid]> arr[mid+1]
            e=mid;
        }
        mid = s + (e-s)/2;
return s;
    }



return -1;

}




int main() {

  int numbers[4];

  cout << "Enter 5 numbers: " << endl;

  //  store input from user to array
  for (int i = 0; i < 4; ++i) {
    cin >> numbers[i];
  }

  cout<< "Peak Element" << Peakelement;
    
    return 0;

}
