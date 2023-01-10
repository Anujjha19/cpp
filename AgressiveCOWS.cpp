/* #include <bits/stdc++.h>
//#include<iostream>

using namespace std;
bool isPossible(int stalls[], int n, int m, int mid) {
   int cowCount = 1;
    int lastPos = stalls[0];
    
    for(int i=0; i<n; i++ ){
        
        if(stalls[i]-lastPos >= mid){
            cowCount++;
            if(cowCount==k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}


int aggressiveCows(int stalls[], int n , int m){
    int s=0;
    int maxi =-1;
    for(int i=0; i<n; i++){
        maxi=max(maxi , stalls[i]);

    }
    int e=maxi;
 int ans =-1;
    int mid= s+(e-s)/2;

   while(s<=e){
    //sort(stalls ,n);
    sort(stalls[0], stalls[n-1] );
    if(isPossible(stalls , n, m , mid)){
        ans=mid;
        s=mid+1;

    }
    else{
        e=mid-1;
    }
    mid=s+(e-s)/2;

}
return ans;


}


int main(){
    int n=4;
    int m=2;
    int stalls[4]={10,20,30,40};

    cout << "The maximum value of the two cows can be placed is: " << aggressiveCows(stalls, n, m) << endl;

} */

/* C++ code to find the largest minimum distance in the problem Aggressive Cows*/
#include <bits/stdc++.h>
using namespace std;

/*function to check if it is possible to place the cows such that the minimum distance between the cows is currDist*/
bool isPossible(int currDist, int POS[], int numStalls, int numCows)
{
    int prevPos = POS[0]; //place the first cow at the first stall
    int numCowsPlaced = 1;

    for (int i = 1; i < numStalls; i++)
    {
        /*check if the distance is greater than or equal to currDist*/
        if (POS[i] - prevPos >= currDist)
        {
            prevPos = POS[i]; //update prevPos
            numCowsPlaced++;  //increment number of cows placed by one
        }
        /*If all cows have been placed with minimum distance = currDist*/
        if (numCowsPlaced == numCows)
        {
            return true;
        }
    }

    /*not possible to place the cows with minimum distance = currDist*/
    return false;
}

int largestMinimumDistance(int numStalls, int numCows, int POS[])
{
    /*sort the array POS*/
    sort(POS, POS + numStalls);
    int high = POS[numStalls - 1] - POS[0];
    int low = 1;
    int largestMin = low; //initialize it with minDist

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(mid, POS, numStalls, numCows))
        {
            largestMin = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return largestMin;
}

int main()
{
    int numStalls = 5;
    int numCows = 3;
    int POS[numStalls] = {4, 2, 1, 3, 6};

    cout << "The largest minimum distance possible is: " << largestMinimumDistance(numStalls, numCows, POS) << endl;
}