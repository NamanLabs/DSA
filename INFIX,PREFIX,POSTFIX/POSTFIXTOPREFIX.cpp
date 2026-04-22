#include<iostream>
#include<stack>
using namespace std;
string solve(string val1,string val2,char op1){
    string s ="";
    s.push_back(op1);    
    s += val1;
    s += val2;

}
int main(){
    string s = "79+4*8/3-";
    // we need 1 stack for vals
    stack<string> val;
    for( int i =0;i<s.length();i++){
        //check if s[i] is a digitor not
        if(s[i]>=48 && s[i]<=57){
            val.push(to_string(s[i]-48));
        }
        else { // is op +,-,*,/
            string val2 = val.top();
            val.pop();
            string val1 = val.top();
            val.pop();
            string ans = solve(val1,val2,s[i]);
            val.push(ans);
        }
    }
    cout<<val.top()<<endl;
    cout<<(2+6)*4/8-3;
}
