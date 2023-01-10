#include <iostream>
using namespace std;

void printArray(int array[], int size) {
for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
}
cout << endl;
}

void insertionSort(int array[], int n){
    
    for(int i = 1; i<n; i++) {
        int temp = array[i];
        int j = i-1;
        for(; j>=0; j--) {
            
            if(array[j] > temp) {
                //shift
                array[j+1] = array[j];
            }
            else { // ruk jao
                break;
            }
            
        }
        //copy temp value
        array[j+1] = temp;  
    } 
}

/* void insertionSort(int n, vector<int> &arr){
    // Write your code here.
    for(int i = 1; i<n; i++) {
       int j=i-1;
        int temp=arr[i];
        while(j>=0 &&  (arr[j]>temp)){

                arr[j+1]=arr[j];

            else{
                break;
            }
            j--;
        }

        arr[j+1]=temp;
    }
} */

int main(){
    int data[] = {20, 12, 10, 15, 2};
int size = sizeof(data) / sizeof(data[0]);
insertionSort(data, size);
cout << "Sorted array in Acsending Order:\n";
printArray(data, size);
}
