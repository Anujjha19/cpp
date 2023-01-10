#include<iostream>
#include<vector>
using namespace std;



int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    int arr[n][m];

    cout << "Enter the elements as INPUTS " <<  endl;
    //taking input -> row wise input
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            cin >> arr[row][col];
        }
    }




    cout << "Printing the array " << endl;
    //print 
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
    

 
vector<int> wavePrint(Vector<vector><int>> arr , int nRows , int mCols){
    vector<int> ans;
    for(int col=0; col<mCols; col++){
        if (col &1){
            //odd Index -> Bottom to top
            for(int row =nRows-1; row>=0; row--){
                ans.push_back(arr[row][col]);
            }
        }
        else{
            for(int row=0; row<nRows; row++){
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}
}

