

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
//  Created on: 2018-11-15 14:30:00
// using linear search
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<climits>
using namespace std;
int main() {
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int target =9;
    for(int i =0;i<n;i++){
        if(arr[i]>target){
            cout<<"lower bound : "<<arr[i-2]<<" "; ///lower bound
            cout<<"Upper Bound : "<<arr[i]<<" "; /////Upper bound
            break;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
 //  Created on: 2018-11-15 14:30:00
 // using binary search
 // Note: Binary search only works on sorted array
////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<climits>
using namespace std;
int main() {
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int target =9;
    int lo = 0;
    int hi =n-1;
    bool flag =false;
    while(lo<=hi){
        int mid = lo +(hi-lo)/2;
        if(arr[mid]==target){
            flag =true;
            cout<<arr[mid-1];
            break;
        }
        else if (arr[mid]<target) lo =mid+1;
        else hi = mid -1;
    }
    if (flag == false) cout<<arr[hi];////print lower bound
    return 0;
}
///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////For upper bound using binary search
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#include<iostream>
#include<climits>
using namespace std;
int main() {
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int target =9;
    int lo = 0;
    int hi =n-1;
    bool flag =false;
    while(lo<=hi){
        int mid = lo +(hi-lo)/2;
        if(arr[mid]==target){
            flag =true;
            cout<<arr[mid+1];
            break;
        }
        else if (arr[mid]<target) lo =mid+1;
        else hi = mid -1;
    }
    if (flag == false) cout<<arr[lo];////print upper bound
    return 0;
}