#include<iostream>
#include<climits>
using namespace std;
int main() {
    int n;
    cout<<"Enter the no. of students:";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Enter marks of student "<<i+1<<": ";
        cin>>arr[i];
    }
    for(int i=0; i<n; i++)
    {
        if(arr[i]<35) cout<<i<<" ";
    }
    return 0;
}