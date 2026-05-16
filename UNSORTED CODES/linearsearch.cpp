#include<iostream>
using namespace std;
int linearsearch(int arr[],int n,int key){
    for (int i=0; i<n ; i++ ){
        if(arr[i]==key)
         {   return i;}
        
    }
    return -1;
}
int main(){
    int n,key;
    cout<<"Enter size of array & element to be found:";
    cin>>n>>key;
    int arr[n];
    cout<<"Enter elements of array:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<linearsearch(arr,n,key);
    return 0;
}