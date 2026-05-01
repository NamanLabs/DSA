#include<iostream>
using namespace std;
class node{
public:
    int val;
    node* next;
    node(int val){
        this->val =val;
        this->next=NULL;
    }
};
class Queue{
    public:
    node* head;
    node*tail;
    int s;
    Queue(){
        head = tail =NULL;
        s=0;
    }
    void push(int val){
        node* temp = new node(val);
        if(s==0) head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
        s++;
    }
    void pop(){
        if(s ==0){
            cout<<"Queue is Empty!";
            return;
        }
        node *temp =head;
        head = head->next;
        s--;
        delete(temp);
    }
    int front(){
        if(s ==0){
            cout<<"Queue is Empty!";
            return -1;
        }
        return head->val;
    }
    int back(){
        if(s ==0){
            cout<<"Queue is Empty!";
            return -1;
        }
        return tail->val;
    }
    void display(){
        node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<endl;
    }
    int size(){
        return s;
    }
    bool empty(){
        if(s==0) return true;
        else return false;
    }
};
int main(){
    Queue q;
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
    return 0;
}