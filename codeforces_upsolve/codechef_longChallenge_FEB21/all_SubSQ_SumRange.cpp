#include<bits/stdc++.h>
#define ll long long
using namespace std;
void display(vector<ll>sx){
    for(ll c:sx)
        cout<<c<<" ";
    cout<<"\n";
}
void subsequence(vector<ll>arr,ll start,ll ssf,ll size,vector<ll>&fill,ll limit){
    if(size==limit){
        fill[size-1]+=ssf;
        if(size==arr.size())
        return;
    }
    for(int i=start;i<arr.size();i++)
        subsequence(arr,i+1,ssf+ssf^arr[i],size+1,fill,limit);
}
int main(){
    ll MOD=998244353;
    ll N;vector<ll>arr;
    cin>>N;
    vector<ll>fill(N,0);
    while(N--){
        ll item;cin>>item;
        arr.push_back(item);
    }
    // display(fill);
    ll Q;
    cin>>Q;
    while(Q--){
        ll q;
        cin>>q;
        subsequence(arr,0,0,0,fill,q);
        for(ll i=1;i<=q-1;i++)
        fill[i]=((fill[i]%MOD)+(fill[i-1]%MOD))%MOD;
        cout<<fill[q-1]<<"\n";
    }
}