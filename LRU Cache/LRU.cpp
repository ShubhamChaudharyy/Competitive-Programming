#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left,*right;
}*head=NULL,*tail=NULL;
void put(int value){
    Node *newNode=new Node();
    newNode->data=value;
    newNode->left=tail;
    newNode->right=NULL;
    tail->right=newNode;
    tail=newNode;  
}
void display(){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->right;
    }
}
int main(){
    Node *obj=new Node();
    obj->data=3;
    obj->right=NULL;
    obj->left=NULL;
    head=obj;
    tail=head;
    put(5);
    put(4);
    put(9);
    put(4);
    display();
}