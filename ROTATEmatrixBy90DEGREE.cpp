#include<iostream>
#include<vector>
using namespace std;


void rotate(int n, vector<vector<int>> &arr){
    
    // Transpose
    for(int i=0; i <n; i++){
        for( int j= i; j<n; j++){
            swap(arr[i][j], arr[j][i]);

        }
    }

    // Col swap
     for(int i=0; i <n; i++){
        int li=0; // first column
        int ri= n-1; // last column
         while(li<ri){
            swap(arr[i][li], arr[i][ri]);
            li++;
            ri--;
         }

     }
     // Dispaly Print
     for(int i=0; i <n; i++){
        for( int j= 0; j<n; j++){
            cout<< arr[i][j];
        }
        cout<<endl;

     }
}
int main(){
    int n;
    cin >>n;
    vector<vector<int>> arr(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for( int j=0; j<n; j++){
            cin>> arr[i][j];

        }
    }
    rotate(n,arr);
} 
