#include<iostream>
using namespace std;
int binarySearch(int a[],int n,int key){
int l=0,h=n-1;
while(l<=h){
int m=(l+h)/2;
if(a[m]==key)return m;
else if(a[m]<key)l=m+1;
else h=m-1;
}
return -1;
}
int main(){
int n,key;
cin>>n;
int a[n];
for(int i=0;i<n;i++)cin>>a[i];
cin>>key;
int i=binarySearch(a,n,key);
cout<<i;
return 0;
}
