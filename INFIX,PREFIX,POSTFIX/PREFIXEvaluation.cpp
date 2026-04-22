#include<iostream>
#include<stack>
using namespace std;
int solve(int val1,int val2,char op1){
    if (op1 =='+') return val1+val2;
    else if (op1 =='-') return val1-val2;
    else if (op1 =='*') return val1*val2;
    else return val1/val2;
}
int main(){
    string s = "-/*+79483";  //PREFIX EVALUATION
    // we need 1 stack for vals
    stack<int> val;
    for( int i =s.length()-1;i>=0;i--){
        //check if s[i] is a digitor not
        if(s[i]>=48 && s[i]<=57){
            val.push(s[i]-48);
        }
        else { // is op +,-,*,/
            int val1 = val.top();
            val.pop();
            int val2 = val.top();
            val.pop();
            int ans = solve(val1,val2,s[i]);
            val.push(ans);
        }
    }
    cout<<val.top()<<endl;
    return 0;
}