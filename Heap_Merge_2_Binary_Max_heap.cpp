// C++ program to merge two max heaps.
#include <bits/stdc++.h>
using namespace std;

void maxHeapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2* i + 2;

    if( left < N && (arr[largest] < arr[left])){
        largest= left;
    }
    if( right < N && (arr[largest] < arr[right])){
        largest= right;
    }

    if( largest != i){
        swap( arr[largest] , arr[i]);
        maxHeapify( arr , N , largest);
    }
}

void buildMaxHeap(int arr[], int N)
{
    for( int i= N/2 -1  ; i >=0 ; i--){
        maxHeapify( arr , N , i);
    } 
}

// Merges max heaps a[] and b[] into merged[]
void mergeHeaps(int merged[], int a[], int b[], int N, int M)
{
    int nm = N+M;


        for( int i= 0 ; i< N; i++){
            merged[i] = a[i];
        }
        
        for( int i= 0 ; i< M; i++){
            merged[N+i] = b[i];
        }
        
        
        buildMaxHeap( merged, nm );
        

}

// Driver's code
int main()
{
    int a[] = {10, 5, 6, 2};
    int b[] = {12, 7, 9};

    int N = sizeof(a) / sizeof(a[0]);
    int M = sizeof(b) / sizeof(b[0]);

    int merged[N + M];

    // Function call
    mergeHeaps(merged, a, b, N, M);

    for (int i = 0; i < N + M; i++)
        cout << merged[i] << " ";

    return 0;
}
