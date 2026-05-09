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
        st.push(temp.top());
        temp.pop();
    }
}
void pushatindex(stack<int>&st,int index,int val){
    stack <int> temp;
    while(st.size()>index){
        temp.push(st.top());
        st.pop();
        
    }
    st.push(val);
    while(temp.size()>0){
        st.push(temp.top());
        temp.pop();
    }
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
    pushatbottom(st,80);
    print(st);
    cout<<endl;
    pushatindex(st,2,90);
    print(st);
    cout<<endl;
    return 0;
}