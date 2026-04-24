#include<iostream>
#include<climits>
using namespace std;
int main() {
    bool p = false;
    bool q =false;
    bool r = true;
    cout<<(p == q == r);// false =false print 1 then (as 1 =true) so true == true therefore output is 1(i.e. true)
    // always go left to right
    return 0;
}