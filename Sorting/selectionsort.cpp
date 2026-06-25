#include<iostream>
#include<climits>
using namespace std;
int main() {
    int arr[]={1,4,2,6,34,9,54,2,46,89};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int ele :arr){
        cout<<ele<<" "<<endl;
    }
    cout<<endl;
    //////////////////////////////////////////////////
    ///////////////////////////////////////////////
    //selection sort////////////////////////////////
    for(int i=0;i<n-1;i++){
        int min = INT_MAX;
        int mindidx = -1;
        for(int j=i;j<n;j++){
            if(arr[j]<min){
                min = arr[j];
                mindidx = j;
            }
        }
        swap(arr[i],arr[mindidx]);
    }
    for(int ele :arr){
        cout<<ele<<" "<<endl;
    }
}