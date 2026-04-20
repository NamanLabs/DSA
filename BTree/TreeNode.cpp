#include<iostream>
#include<climits>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val= val;
        this->right=right;
        this->left=left;
    }
};
void Display(Node*root){ 
    if(root==NULL) return;
    cout<<root->val<<" ";
    Display(root->left);
    Display(root->right);
}
int sum(Node*root){
    if (root==NULL) return 0;
    return root->val + sum(root->left)+sum(root->right);
}
int sizeoftree(Node*root){
    if(root ==NULL) return 0;
    return 1  + sizeoftree(root->left)+sizeoftree(root->right);
}
int maxoftree(Node*root){
    if(root ==NULL) return INT_MIN;
    int lmax = maxoftree(root->left);
    int rmax = maxoftree(root->right);
    return max(root->val,max(rmax,lmax));
}
int Product(Node*root){
    if (root==NULL) return 1;
    return root->val * Product(root->left) * Product(root->right);
}
int minoftree(Node*root){
    if (root==NULL) return INT_MAX;
    return min( root->val ,min(minoftree(root->left),minoftree(root->right)));
}
int leveloftree(Node*root){
    if(root==NULL) return 0;
    return 1 + max(leveloftree(root->left),leveloftree(root->right));
}
int main(){
    Node* a =new Node(1);
    Node* b =new Node(2);
    Node* c =new Node(3);
    Node* d =new Node(4);
    Node* e =new Node(5);
    Node* f =new Node(6);
    Node* g =new Node(7);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    Display(a);
    cout<<endl;
    cout<<sum(a);
    cout<<endl;
    cout<<sizeoftree(a);
    cout<<endl;
    cout<<maxoftree(a);
    cout<<endl;
    cout<<Product(a);
    cout<<endl;
    cout<<minoftree(a);
    return 0;
}