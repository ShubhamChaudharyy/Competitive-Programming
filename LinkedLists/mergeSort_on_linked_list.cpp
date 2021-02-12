#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next=NULL;
};
void display(Node *start,Node *end){
    while(start!=end->next){
        cout<<start->data<<" ";
        start=start->next;
    }
    cout<<"\n";
}
void merge(Node *h1,Node *h2,Node *mid){
    if(h1->next==h2){
        h1->data=min(h1->data,h2->data);
        h1=h1->next;
        h1->data=min(h1->data,h2->data);
    }
    else{
        Node *h12=mid->next;
        Node *iter=h1;
        while(h1!=mid->next && h12!=h2->next){
            if(h1->data <= h12->data){
                iter->data=h1->data;
                h1=h1->next;
            }
            else if(h1->data > h12->data){
                iter->data=h2->data;
                h1=h2->next;
            }
            iter=iter->next;
        }
        while(h1!=mid->next){
            iter->data=h1->data;
            h1=h1->next;
        }
        while(h12!=h2->next){
            iter->data=h12->data;
            h12=h12->next;
        }
    }
    display(h1,h2);
}
void sort(Node *start,Node *end){
    Node *fast=start;
    Node *slow=start;
    if(start==end)
        return;
    if(start->next==end){
        merge(start,end,start);
        return;
    }
    while(fast!=end->next){
        slow=slow->next;fast=fast->next->next;
    }
    Node *midNext=slow->next;
    sort(start,slow);
    sort(midNext,fast);
    cout<<start->data<<" "<<end->data<<"\n";
    merge(start,end,slow);
}
int main(){
    vector<int>vec={1,2,3,4,5,6};
    Node *head=new Node;
    Node *tail=new Node;
    head=tail;
    for(int i=0;i<vec.size();i++){
        Node *temp=new Node;
        tail->data=vec[i];
        if(i==vec.size()-1){
            tail->next=NULL;
            break;
        }
        tail->next=temp;
        tail=tail->next;
    }
    Node *tempHead=head;
    Node *tempTail=head;
    sort(tempHead,tail);

}