#include<iostream>
#include<stack>
using namespace std;
int priority(char op1){
    if(op1 =='+'|| op1=='-') return 1;
    return 2;
}
string solve(string val1,string val2,char op1){
    string s ="";
    s += val1;
    s+=val2;
    s.push_back(op1);
    return s;
}
int main(){
    string s = "(2+6)*4/8-3";
    // we need to stacks 1 for vals, 1 for ops
    stack<string> val;
    stack<char> op;
    for( int i =0;i<s.length();i++){
        //check if s[i] is a digitor not
        if(s[i]>=48 && s[i]<=57){
            val.push(to_string(s[i]-48));
        }
        else { // is op +,-,*,/
            if(op.size()==0) op.push(s[i]);
            else if(s[i]=='(') op.push(s[i]);
            else if(op.top()=='(') op.push(s[i]);
            else if (s[i] == ')'){
                while(op.top()!='(') {
                    char op1= op.top();
                    op.pop();
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop();
                    string ans = solve(val1,val2,op1);
                    val.push(ans);
                }
                op.pop();
            }
            else if ( priority(s[i])>priority(op.top())) op.push(s[i]);
            else { /// in this priority(s[i]) <= priority(op.top())  
                while(op.size()>0 && priority(s[i]) <= priority(op.top())){
                    // in this we have to do val1 op val2
                    char op1= op.top();
                    op.pop();
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop();
                    string ans = solve(val1,val2,op1);
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    // to ensure stack is empty
    //do work
    if(op.size()>0) {
        char op1= op.top();
        op.pop();
        string val2 = val.top();
        val.pop();
        string val1 = val.top();
        val.pop();
        string ans = solve(val1,val2,op1);
        val.push(ans);
    }
    cout<<val.top()<<endl;
    cout<<(2+6)*4/8-3;
}