#include<iostream>
#include<climits>
#include<vector>
using namespace std;
void merge(vector<int> & a,vector<int> & b,vector<int>& res){
    int i=0; //a
    int j=0; // b
    int k=0;  // res
    while(i<a.size() && j<b.size()){
        if(a[i]<=b[j]){
            res[k]=a[i];
            i++;
            k++;
        }else{
            res[k]=b[j];
            k++;
            j++;
        }
    }
    if(i==a.size()){     // a is at end
        while(j<b.size()){
            res[k]=b[j];
            j++;
            k++;
        }
    }
    if(j==b.size()){  // b is at end
        while(i<a.size()){
            res[k]=a[i];
            i++;
            k++;
        }
    }
}
void mergesort(vector<int> & v){
    int n =v.size();
    if (n==1) return;
    int n1 = n/2;
    int n2 = n-n1;
    vector<int>a(n1);
    vector<int>b(n2);
    // can be wriiten as   int n1=n/2,n2=n-n1
    // vector wali line ko vector<int> a(n1) ,b(n2) bhi likh sakte hai
    //copy pasting arrays
    for(int i=0;i<n1;i++){
        a[i]=v[i];
    }
    for(int i=0;i<n2;i++){
        b[i]=v[n1+i];
    }
    mergesort(a);
    mergesort(b);
    merge(a,b,v);
    a.clear();
    b.clear();
}
int main() {
    // int arr[]={1,4,5,8};
    // int n1 = sizeof(arr) / sizeof(arr[0]);
    // int brr[]={2,6,7,10,12};
    // int n2 = sizeof(brr) / sizeof(brr[0]);
    // vector<int>a(arr,arr+n1);
    // vector<int>b(brr,brr+n2);
    // vector<int> res(n1+n2);
    // merge(a,b,res);
    // for(int i=0;i<res.size();i++){
    //     cout<<res[i]<<" ";
    // }
    //////////////////////////////////////////////
    ////////////////////////////////////////////
    //////////////FINAL////////////////////////
    int arr[]={1,23,46,78,53,21,234,567,89,54321,356,76543,2245,56,775,32,1,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr,arr+n);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    mergesort(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}