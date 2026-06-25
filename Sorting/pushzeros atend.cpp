#include<iostream>
#include<climits>
using namespace std;
int main() {
    int arr[9]={5,0,1,2,0,0,4,0,3};
    int n = 9;
    for(int i =0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    for(int i =0;i<n-1;i++){// n-1 phases
        for(int j =0;j<n-1-i;j++){//traverse and -i becuse we dont need to recheck last term after seting
            if(arr[j] == 0){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    cout<<endl;
    for(int i =0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
}       