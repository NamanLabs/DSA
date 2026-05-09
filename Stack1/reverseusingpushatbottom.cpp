#include<iostream>
#include<stack>
using namespace std;
void print (stack<int>&st){
    stack <int> temp;
    while(st.size()>0){
        temp.push(st.top());
        st.pop();
        
    }
    // putting elements back in stack
    while(temp.size()>0){
        cout<<temp.top()<<" ";
        int x = temp.top();
        temp.pop();
        st.push(x);
    }
    cout<<endl;
}
void pushatbottom(stack<int>&st,int val){
    stack <int> temp;
    while(st.size()>0){
        temp.push(st.top());
        st.pop();
        
    }
    st.push(val);
    while(temp.size()>0){
        // cout<<temp.top()<<" ";                  we will stop cout here because it affect output 
        st.push(temp.top());
        temp.pop();
    }
}
void reverse(stack<int>&st){
    if(st.size()==1) return;
    int x = st.top();
    st.pop();
    reverse(st);
    pushatbottom(st,x);
    }
int main(){
    stack <int> st;
    stack<int>temp;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    print(st);
   // pushatbottom(st,80);
    reverse(st);
    print(st);
    return 0;
}