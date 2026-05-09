#include<iostream>
#include<stack>
using namespace std;
void print (stack<int>st){
    stack <int> temp;
    while(st.size()>0){
        temp.push(st.top());
        st.pop();
        
    }


    // putting elements back in stack
    while(temp.size()>0){
        cout<<temp.top()<<endl;
        int x = temp.top();
        temp.pop();
        st.push(x);
    }

}
int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    // st to gt
    stack<int>gt;
    stack<int>rt;
    print(st);
    while(st.size()>0){
        int x = st.top();
        st.pop();
        gt.push(x);
    }
    // gt to rt
    while(gt.size()>0){
        int x = gt.top();
        gt.pop();
        rt.push(x);
    }
    // rt to st
    while(rt.size()>0){
        int x = rt.top();
        rt.pop();
        st.push(x);
    }
    print(st);
    cout<<st.size()<<endl;
    cout<<gt.size()<<endl;
    cout<<rt.size()<<endl;
}



