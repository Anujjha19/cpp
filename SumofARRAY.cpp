/* #include<iostream>
using namespace std;

int sumArr(int arr[], int n){

    int sum =0;

    for( int i=0; i<n; i++){

        sum=+arr[i];
        
    }
    return sum;
}

int main(){

int n;
    cin >> n;

    int num[100];

    //taking input in array
    for(int i = 0; i<n; i++) {
        cin >> num[i];
    }

    cout<<"Sum of all elements of Array :" <<  sumArr(num , n) << endl;
    return 0;

}
 */
#include<iostream>

using namespace std;
int main()
{
   int arr[10], i, sum=0;
   cout<<"Enter 10 Array Elements: ";
   for(i=0; i<10; i++)
      cin>>arr[i];
   for(i=0; i<10; i++)
      sum = sum+arr[i];
   cout<<"\nSum of all array elements = "<<sum;
   cout<<endl;
   return 0;
}