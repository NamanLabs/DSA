#include<iostream>
#include<vector>
using namespace std;
class Queue{
public:
    vector<int>arr;
    int f;
    int b;
    Queue(int val){
        f = 0 ;
        b=0;
        vector<int>v(val);
        arr =v;
    }
    void push(int val){
        if(b==10){
            cout<<"Queue is FULL";
            return;
        } else {
            arr[b] = val;
            b++;
        }
    }
    void pop(){
        if(b-f ==0) {
            cout<<"Queue is EMPTY";
            return;
        } else{
            f++;
        }
    }
    int size(){
        cout<<b-f<<endl;
        return b-f;
    }
    int front(){
        if(b-f==0){
            cout<<"Queue is EMPTY";
            return -1;
        }
        cout<<arr[f]<<endl;
        return arr[f];
    }
    int back(){
        if(b-f==0){
            cout<<"Queue is EMPTY";
            return -1;
        }
        cout<<arr[b-1]<<endl;
        return arr[b-1];
    }
    bool empty(){
        if (b-f == 0){
            cout<<true<<endl;
            return true;
        }
        else{
            cout<<false<<endl;
            return false;  
        } 
    }
    void display(){
        for (int i = f;i<b;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}; 


int main(){
    Queue q(10);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.display();
    q.pop();
    q.display();
    q.size();
    q.front();
    q.back();
    q.empty();
}