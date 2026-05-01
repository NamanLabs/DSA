#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void display(queue<int>&q){
    int n = q.size();
    for(int i =0 ; i<n;i++){
        int x =q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
    cout<<endl;
}
void reverse(queue<int>&q){
    stack<int> st;
    // pop elements from queue and push to stack
    while(q.size()>0){
        int x = q.front();
        q.pop();
        st.push(x);
    }
    // put elements back to queue
    while(st.size()>0){
        int x = st.top();
        st.pop();
        q.push(x);
    }
}

int main(){
    queue<int>q;
    //push
    //pop
    //front->top
    //size,empty
    //back
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout<<q.size()<<endl;
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    q.pop();
    cout<<q.size()<<endl;
    cout<<q.front()<<endl;


    display(q);
    reverse(q);
    display(q);
}