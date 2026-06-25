#include<iostream>
#include<climits>
using namespace std;
int main() {
     int arr[]={1,4,2,6,34,9,54,2,46,89};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //////////////////////////////////////////////////
    ///////////////////////////////////////////////
    //insertion sort////////////////////////////////
   for (int i =1;i<n;i++){
        int j =i;
        while(j>=i){
            if(arr[j]>=arr[j-1]) break;
            else swap(arr[j],arr[j-1]);
            j--;

        }
    }
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}






//////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
    // sort//////////////////////////////// way 2
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<climits>
using namespace std;
int main() {
     int arr[]={1,4,2,6,34,9,54,2,46,89};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //////////////////////////////////////////////////
    ///////////////////////////////////////////////
    //insertion sort////////////////////////////////
   for (int i =1;i<n;i++){
        int j =i;
        while(j>=i && arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}