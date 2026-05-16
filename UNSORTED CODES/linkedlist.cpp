#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
};
class linkedlist{
    private:
    node*head;
    public:
    linkedlist(){
        head = NULL;
    }
    void insertatbeginning(int value){
    node* newNode = new node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}
    void insertatend(int value){
        node* newNode = new node();
        newNode->data = value;
        newNode->next = NULL;
        if(head == NULL) {
            head = newNode;
            return;
        }
        node* temp = head;
        while(temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void reverse(){
        node* prev = NULL;
        node* current = head;
        node* nextNode;
        while(current!= NULL){
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
    }
    bool detectloop(){
        node* slow = head;
        node* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
    node*gethead(){
        return head;
    }
    void display(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main(){
    linkedlist list;
    list.insertatbeginning(10);
    list.insertatbeginning(20);
    list.insertatend(30);
    list.display();
    list.reverse();
    return 0;
}