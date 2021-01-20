#include<bits/stdc++.h>
using namespace std;
int size=0;
struct Node{
    int data;
    struct Node *left,*right;
};
struct ms{
    int info;
    struct ms *left,*right;
}*head=NULL;
void middle(){

}
void del(){
    while(head!=NULL){
        cout<<head->data;
        head=head->left;
    }
}
void insert(int x){
    
    if(head==NULL){
        Node *newNode=new Node();
        newNode->data=x;
        newNode->left=NULL;
    }
    else{
        Node *newNode=new Node();
        newNode->data=x;
        newNode->left=head;
        newNode->right=NULL;
    }
    if(size==1){
        ms *head=new ms();
    }

}
int main(){
    insert(4);
    insert(6);
    del();
    return 0;
}