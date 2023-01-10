#include<iostream>
using namespace std;

int FirstElement(int arr[], int n, int key){
    int s=0;
    int e=n-1;
    int mid= s+(e-s)/2;
    int ans=-1;
    while(s<=e){
     

        if(arr[mid] == key){
            ans=mid;
            e=mid-1;
        }
        //goto right
        else if(key > arr[mid]){
            s=mid+1;
        }
        else if (key < arr[mid])
         {
            e=mid-1 ;
        }

       // mid=(s+e)/2;
       mid= s + (e-s)/2;
    }
return ans ;
}
int LastElement(int arr[], int n, int key){
    int s=0;
    int e=n-1;
    int mid= s+(e-s)/2;
    int ans=-1;
    while(s<=e){
     

        if(arr[mid] == key){
            ans=mid;
            s=mid+1;
        }
        //goto right
        else if(key > arr[mid]){
            s=mid+1;
        }
        else if (key < arr[mid])
         {
            e=mid-1 ;
        }

       // mid=(s+e)/2;
       mid= s + (e-s)/2;
    }
return ans ;
}

int main(){
    
    int arr[6]={0,0,0,1,1,5};

    //int arr =FirstElement(arr, 6 ,0 );
    
    cout<<"First Position " <<FirstElement(arr, 6 ,6 ) <<endl;
    cout<<endl;
   cout<<"Last Position " <<LastElement(arr, 6 ,6 ) <<endl;


    return 0;

}