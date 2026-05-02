////////////////////////////parametrized method////////////////////////////////
#include<iostream>
#include<climits>
using namespace std;
void sum1toN(int sum,int n){
    if(n == 0) {
        cout<<sum<<endl;
        return;
    }
    sum1toN(sum+n, n-1);
}
int main() {
    sum1toN(1,1000);
    return 0;
}