#include <iostream>
using namespace std;
int main() {
    int rows, cols;

     cout << "Enter the number of rows: ";
     cin >> rows;
     cout << "Enter the number of columns: ";
     cin >> cols;
    int arr[rows][cols];
    int sum=0;
    for(int i =0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>arr[i][j];
        }    
    }
    
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++){
            sum=sum+arr[i][j];
        }
        cout<<sum<<endl;
        sum=0;
    }
     for(int j=0;j<cols;j++){
        for(int i=0;i<rows;i++){
            sum=sum+arr[i][j];
        }
        
    cout<<sum<<endl;
    sum=0;
    }
    return 0;
}
