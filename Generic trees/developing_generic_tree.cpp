#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Node{
    public:
    ll data;
    vector<Node *>edges;
}*root=NULL;
void recurse(ll i,vector<ll>ip,stack<Node *>&s){
    if(i==ip.size())
    return;
    if(ip[i]==-1){
        if(!s.empty())
            s.pop();
    } 
    else {
        Node *temp=new Node();
        temp->data=ip[i];
        if(i==0)
            root=temp;
        if(!s.empty()){
            Node *Top=s.top();
            Top->edges.push_back(temp);
        }
        s.push(temp);
    }
    recurse(i+1,ip,s);
}
void display(Node *head){
    cout<<head->data<<": ";
    for(ll i=0;i<head->edges.size();i++)
        cout<<head->edges[i]->data<<" ";
    cout<<"\n";
    for(ll i=0;i<head->edges.size();i++)
        display(head->edges[i]);
    return;
}
ll Size(Node *head){
    ll output=1;
    for(ll i=0;i<head->edges.size();i++)
        output+=Size(head->edges[i]);
    return output;
}
ll Max(Node *head,ll ans){
    ans=max(head->data,ans);
    for(ll i=0;i<head->edges.size();i++)
        ans=max(ans,Max(head->edges[i],ans));
    return ans;
}
ll height(Node *head,ll dsf){
    ll ans=dsf;
    for(ll i=0;i<head->edges.size();i++)
        ans=max(ans,height(head->edges[i],dsf+1));
    return ans;
}
void flow(Node *head){
    cout<<"Node -> Pre "<<head->data<<"\n";
    for(ll i=0;i<head->edges.size();i++){
        cout<<"Node -> Pre -> edge "<<head->data<<" "<<head->edges[i]->data<<"\n";
        flow(head->edges[i]);
        cout<<"Node -> Post -> edge "<<head->data<<" "<<head->edges[i]->data<<"\n";
    }
    cout<<"Node ->Post "<<head->data<<"\n";
}
void inorder(Node *head){
    for(ll i=0;i<head->edges.size();i++){
        inorder(head->edges[i]);
        cout<<"Node -> Post -> edge "<<head->data<<" "<<head->edges[i]->data<<"\n";
    }
}
void swap(){

}
void mirror(Node *head){
    for(ll i=0;i<head->edges.size();i++)
        mirror(head->edges[i]);
    reverse(head->edges.begin(),head->edges.end());
    return;
}
void removeLeaves(Node *head){
    for(int i=head->edges.size()-1;i>=0;i--){
        auto it=head->edges.begin();
        if(head->edges[i]->edges.size()==0){
            head->edges.erase(it+i);
        }
        else
        removeLeaves(head->edges[i]);
    }
}
bool path(Node *head,bool &f,int val,vector<int>&fill){
    if(head->data==val)
    return true;
    for(Node *child:head->edges){
        if(path(child,f,val,fill)){
            fill.push_back(child->data);
            return true;
        }
    }
    return false;
}
Node* linear(Node *head){
    if(head->edges.size()==0)
    return head;
    Node *lastNULL;
    for(int i=0;i<head->edges.size();i++){
        lastNULL=linear(head->edges[i]);
        if(i+1<head->edges.size())
        lastNULL->edges.push_back(head->edges[i+1]);
    }
    auto it=head->edges.begin();it++;auto it2=head->edges.end();
    head->edges.erase(it,it2);
    return lastNULL;
}
void LCA(Node *head, int a,int b){

}
int main(){
    stack<Node *>s;
    vector<ll>input={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    recurse(0,input,s);
    // display(root);
    // cout<<Size(root)<<"\n";
    // cout<<Max(root,0)<<"\n";
    // cout<<height(root,0)<<"\n";
    // flow(root);
    // mirror(root);
    // removeLeaves(root);
    // linear(root);
    display(root);
    bool found=false;
    vector<int>ans;
    path(root,found,110,ans);
    for(int c:ans){
        cout<<c<<"\n";
    }
    return 0;
}