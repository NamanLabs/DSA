// #include<iostream>
// using namespace std;
// int main(){
//     int arr[]={1,2,3,4,5},n;
//     cout<<"Where element should be delted:";
//     cin>>n;
//     arr[n]=0;
//     for(int i =0; i<5;i++){
//         cout<<arr[i]<<" ";
//     }
// return(0);
// // }









// #include<iostream>
// using namespace std;
// int main(){
//     int arr[]={1,2,3,4,5},n;
//     cout<<"Where element should be deleted: ";
//     cin>>n;
//     arr[n]=0;
//     for(int i =0; i<5;i++){
//         if(arr[i] != 0) {
//             cout<<arr[i]<<" ";
//         }
//     }
//     return 0;
// }









































// Online C++ compiler to run C++ program online
#include <iostream>
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
    cout<<"Enter the position where you want to delete the element:";
    cin>>x;
    if(x<0||x>=n){
        cout<<"Invalid position"<<endl;
        return 0;
    }
    for(int i=x;i<=n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;
    cout<<"Array after deletion:";
    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}