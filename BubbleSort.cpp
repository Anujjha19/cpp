#include<iostream>
using namespace std;

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

/* if i=0 to n-1
 j =  0 to n -i-1 
if i =1 to n
 j = 0 to n-i; */


 void bubbleSort(int array[], int size){

    for(int i=1; i <size; i++){
       bool swapped = false;
        //for round 1 to n-1
        for(int j=0; j<size-i; j++){
            if(array[j] > array[j+1])
                swap(array[j], array[j+1]);
            swapped=true;
        }
if(swapped == false)
//already sorted
break;
    }


}


int main(){
    int data[] = {20, 12, 10, 15, 2};
  int size = sizeof(data) / sizeof(data[0]);
  bubbleSort(data, size);
  cout << "Sorted array in Acsending Order:\n";
  printArray(data, size);
} 

