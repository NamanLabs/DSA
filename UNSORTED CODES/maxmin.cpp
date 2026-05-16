#include <iostream>
#include <climits>
using namespace std;
int main() {
    int n,x;
    cout<<"Enter the size of array:";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array:";
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    int MaxElement=INT_MIN;
    int MinElement=INT_MAX;
    for(int i=1;i<n;i++){
        if (arr[i]>MaxElement){
            MaxElement=arr[i];
        }
        if(arr[i]<MinElement){
            MinElement=arr[i];
        }
    }
    cout<<"Maximum Element:"<<MaxElement<<endl;
    cout<<"Minimum Element:"<<MinElement<<endl;
    return 0;
}