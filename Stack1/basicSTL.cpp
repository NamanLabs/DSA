#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> st;
    cout<<st.size()<<endl;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.size()<<endl;
    
    
    // printing by emptying the stack
    // while (st.size()>0){
    //     cout<<st.top()<<endl;
    //     st.pop();
    // }

    // printing by using an stack
    // stack <int> temp;
    // while(st.size()>0){
    //     cout<<st.top();
    //     temp.push(st.top());
    //     st.pop();
        
    // }


    // // putting elements back in stack
    // while(temp.size()>0){
    //     int x = temp.top();
    //     temp.pop();
    //     st.push(x);
    // }
    // cout<<st.top();


    // printing elemnts top to bottom
    stack<int>temp;
    while(st.size()>0){
        cout<<st.top()<<" "<<endl; // bottom to top
        int x = st.top();
        st.pop();
        temp.push(x);

    } 
    while(temp.size()>0){
        cout<<temp.top()<<" "<<endl; // top to bottom
        int a = temp.top();
        temp.pop();
        st.push(a);

    }
    cout<<st.size()<<endl;
    cout<<temp.size()<<endl;

}