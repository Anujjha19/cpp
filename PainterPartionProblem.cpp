#include <bits/stdc++.h>
//#include<iostream>

using namespace std;
bool isPossible(int board[], int n, int m, int mid) {
    int painterCount=1;
    int Boardsection=0;
    for(int i=0; i<n; i++){
        if (Boardsection + board[i] <= mid){
            Boardsection +=board[i];

        }
        else{
            painterCount++;
            if( painterCount > m || board[i] > mid){
                return false;
            }
            Boardsection= board[i];

        }
    }
    return true; 
}


int paint(int board[], int n , int m){
    if(n<m){
        return -1;
    }
 int s=0;
 int sum=0;
 for(int i=0; i<n; i++){
    sum += board[i];
}
int e= sum;
int ans= -1;
int mid = s+(e-s)/2;
while(s<=e){

    if(isPossible(board , n, m , mid)){
        ans=mid;
        e=mid-1;

    }
    else{
        s=mid+1;
    }
    mid=s+(e-s)/2;

}
return ans;

}


int main(){
    int n=4;
    int m=2;
    int board[4]={10,20,30,40};

    cout << "The minimum value of the maximum number of board paint is: " << paint(board, n, m) << endl;

}