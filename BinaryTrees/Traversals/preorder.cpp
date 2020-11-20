#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *left,*right; 
    Node(int val){
        this->data=val;
        left=right=NULL;
    }
};
int preorder(Node *root){
    if(root==NULL)
    return 34;
    cout<<root->data<<"\n";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    struct Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    preorder(root);
}