#include<iostream>
#include<vector>
using namespace std;
class Queue{
public:
    vector<int>arr;
    int f;
    int b;
    int s;
    Queue(int val){
        f = 0 ;
        b=0;
        s=0;
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
            s++;
        }
    }
    void pop(){
        if(s==0) {
            cout<<"Queue is EMPTY";
            return;
        } else{
            f++;
            s--;
        }
    }
    int size(){
        cout<<s<<endl;
        return s;
    }
    int front(){
        if(s==0){
            cout<<"Queue is EMPTY";
            return -1;
        }
        cout<<arr[f]<<endl;
        return arr[f];
    }
    int back(){
        if(s==0){
            cout<<"Queue is EMPTY";
            return -1;
        }
        cout<<arr[b-1]<<endl;
        return arr[b-1];
    }
    bool empty(){
        if (s == 0){
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