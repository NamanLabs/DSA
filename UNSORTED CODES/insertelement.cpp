#include<iostream>
using namespace std;
int main(){
int arr[100]={1,2,3,4,5,6},n;
    cout << "Where element to be inserted\n";
    cin >> n;
    cout << "Enter element:";
cin>> arr[n];
for (int i =0;i<=n;i++)
{
    cout<<arr[i]<<" ";
}
return(0);
}