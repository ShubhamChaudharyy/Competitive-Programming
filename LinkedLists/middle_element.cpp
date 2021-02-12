#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next=NULL;
};
void func(Node *start,Node *end){
    Node *fast=start,*slow=start;
    if(start==end)
    return;
    while(fast!=end){
        fast=fast->next->next;
        slow=slow->next;
    }
    Node *midP1=slow->next;
    func(start,slow);
    func(midP1,end);
    cout<<start->data<<" "<<end->data<<"\n";
}
int main(){
    vector<int>rdm={1,4,2,14,5,9,21,4};
    Node *temp=new Node;
    Node *head=temp;
    for(int i=0;i<rdm.size();i++){
        int c=rdm[i];
        temp->data=c;
        if(i==rdm.size()-1)
        {temp->next=NULL;break;}
        Node *newNode=new Node;
        temp->next=newNode;
        temp=temp->next;
    }
    func(head,temp);
}
// 1 2 3 4 5 6 7