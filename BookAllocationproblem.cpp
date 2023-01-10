#include <bits/stdc++.h>
//#include<iostream>

using namespace std;
bool isPossible(int pages[], int n, int m, int mid) {
    int studentCount=1;
    int pageSum=0;
    for(int i=0; i<n; i++){
        if (pageSum + pages[i] <= mid){
            pageSum +=pages[i];

        }
        else{
            studentCount++;
            if( studentCount > m || pages[i] > mid){
                return false;
            }
            pageSum= pages[i];

        }
    }
    return true; 
}


int allocateBooks(int pages[], int n , int m){
    if(n<m){
        return -1;
    }
 int s=0;
 int sum=0;
 for(int i=0; i<n; i++){
    sum += pages[i];
}
int e= sum;
int ans= -1;
int mid = s+(e-s)/2;
while(s<=e){

    if(isPossible(pages , n, m , mid)){
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
    int pages[4]={10,20,30,40};

    cout << "The minimum value of the maximum number of pages in book allocation is: " << allocateBooks(pages, n, m) << endl;

}