#include<iostream>
#include<vector>
using namespace std;
class Stack{
    public:
    vector <int> v; // unlimited size in vector
    Stack(){

    }
    void push(int val){
       v.push_back(val);
    }
    void pop(){
        if(v.size() == -1){
            cout<<"Stack is empty"<<endl;
            return;
        }
        v.pop_back();
    }
    int top(){
        if(v.size() == -1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return v[v.size()-1];
    }
    int size(){
        return v.size();
    }
};
int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;

}




