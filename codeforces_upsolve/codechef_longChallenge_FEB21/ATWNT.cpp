#include<bits/stdc++.h>
#define ll long long
using namespace std;
void recurse(ll cnv,unordered_map<ll,vector<ll>>mp,unordered_map<ll,vector<ll>>&vtx,ll sf){
    vector<ll>waiting;
    if(mp[cnv].size()==0){
        return;
    }
    for(ll i=0;i<mp[cnv].size();i++){
        vector<ll>temp=recurse(mp[cnv][i],mp[cnv][])
    }
}
int main(){
    ll N;
    cin>>N;
    ll parents=N-1;
    unordered_map<ll,vector<ll>>ump;
    for(ll i=2;i<=N;i++){
        ll pno;
        cin>>pno;
        ump[pno].push_back(i);
    }
    unordered_map<ll,vector<ll>>prts;
    for(ll i=1;i<=N;i++){
        ll sf=1;
        recurse(i,ump,prts,sf);
    }
    return 0;
}