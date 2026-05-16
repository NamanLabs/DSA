#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int x){
    int low = 0, high = n-1;
    
    while(low<=high){
        int mid = (low+high)/2;
        
        if(arr[mid] == x)
            return mid;
        
        else if(arr[mid] > x)
            high = mid-1;
            
        else low = mid+1;
    }
    return -1;
}

int main() {
    int n,x;
    cout<<"Enter size of array:";
    cin>>n;
    
    int arr[n];
    
    for (int i =0; i < n; i++){
        cout<<"Enter element at index: "<<i<<": ";
        cin>>arr[i];
    }
    cout<<endl<<"Enter element to find: ";
    cin>>x;
    
    cout<<"Element was found at index: "<<binarySearch(arr,n,x);

    return 0;
}



























#include <iostream>
using namespace std;
int binarysearch (int arr[],int size,int key){
    int low=arr[0];
    int high=arr[size-1];
    int mid =arr[(size-1)/2];
    while(low<=high){
        if(arr[mid]==key){
            return mid;
        }
        else { 
            if(arr[mid]>key) 
            {
            high=mid-1;}
        else{
            low=mid+1;
        }
        }
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    cout<<"Enter element"
};