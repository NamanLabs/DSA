#include<iostream>
#include<climits>
using namespace std;
int main() {
    bool flag = false;
    for( int i =0 ;i<arr.size()-1;i++){
        for(int j=0;j<arr.size();j++){
            if(arr[i]==arr[j]){
                cout<<arr[i];
                flag = true;
                break;
            }   
        }
        if(flag != false){
            break;
        }
    }
    return 0;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//improvised method
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<climits>
using namespace std;
int main() {
    int n =arr.size();
    int sum;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    int s = n*(n+1)/2;
    cout<<sum-s<<endl;
    return 0;
}