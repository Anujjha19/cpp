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
int arr[10]={1,2,3,3,3,3,3,4,5};

int fisrtoccurence = FirstElement(arr ,10 ,3);
int secondoccurence = LastElement(arr,10,3);

if(fisrtoccurence == -1 && secondoccurence == -1){
    cout<<0;
}

else{
cout<<(secondoccurence-fisrtoccurence)+1<<endl;
 }

}