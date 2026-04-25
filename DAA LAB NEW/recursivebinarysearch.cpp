#include<iostream>
using namespace std;
int binarySearch(int a[],int l,int h,int key){
    if(l>h)return -1;
    int m=(l+h)/2;
    if(a[m]==key)return m;
    else if(a[m]<key)return binarySearch(a,m+1,h,key);
    else return binarySearch(a,l,m-1,key);
}
int main(){
    int n,key;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    cin>>key;
    int i=binarySearch(a,0,n-1,key);
    cout<<i;
    return 0;
}
