#include<iostream>
#include<climits>
using namespace std;
int main() {
    int arr[6]={5,4,3,2,1,10};
    int n = 6;
    for(int i =0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    for(int i =0;i<n-1;i++){// n-1 phases
        for(int j =0;j<n-1-i;j++){//traverse and -i becuse we dont need to recheck last term after seting
            if(arr[j]>arr[j+1]){
                // int temp = arr[j];
                // arr[j] = arr[j+1];
                // arr[j+1] = temp;
                swap(arr[j],arr[j+1]);
            }
        }
    }
    cout<<endl;
    for(int i =0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
}       
/////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////optimized code////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<climits>
using namespace std;
int main() {
    int arr[6]={5,4,3,2,1,10};
    int n = 6;
    for(int i =0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    for(int i =0;i<n-1;i++){// n-1 phases
        bool flag =true;
        for(int j =0;j<n-1-i;j++){//traverse and -i becuse we dont need to recheck last term after seting
            if(arr[j]>arr[j+1]){
                // int temp = arr[j];
                // arr[j] = arr[j+1];
                // arr[j+1] = temp;
                swap(arr[j],arr[j+1]);
                flag = false;
            }
        }
        if (flag == true){
            break;
        }
    }
    cout<<endl;
    for(int i =0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
}       