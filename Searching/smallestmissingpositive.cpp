#include<iostream>
#include<climits>
using namespace std;
int main() {
    int arr[] = {0,1,2,3,4,5,9,12};
    int n =8;
    for(int i =0;i<n;i++){         // using linear search   
        if(arr[i]!=i) {         // using linear search
            cout<< i;         // using linear search
            break;         // using linear search
        }
    } 
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
This solution uses linear search to find the first index where the element is not equal to its index.
*/
#include<iostream>
#include<climits>
using namespace std;
int main() {
    int arr[]={0,1,2,4,5,6,8,100};
    int n = 8;
    int lo=0;
    int hi = n-1;
    int ans = -1;
    while(lo<=hi){
        int mid = lo+ (hi-lo)/2;
        if(arr[mid]==mid) lo = mid+1;
        else{
            ans = mid;
            hi = mid-1;
        }
    }
    cout<<ans;
}