#include<bits/stdc++.h>
#define ll long long
using namespace std;
void recurse(ll Num,vector<ll>vec,ll limit){
    ll fact=2;
    ll orN=Num;
    while(fact<=limit){
        if(Num%fact==0){
            Num=Num/fact;
            vec.push_back(fact);
        }
        else 
        fact++;
    }
    if(Num>2)
    vec.push_back(Num);
    unordered_map<ll,ll>ump;
    for(ll i=0;i<vec.size();i++){
        ll item=vec[i];
        ump[item]++;
    }
    ll Max=0,MaxEle;
    for(auto x:ump){
        if(Max<x.second){
            Max=x.second;
            MaxEle=x.first;
        }
    }
    ll mul=1;
    for(auto x:ump){
        if(x.first!=MaxEle){
            for(ll iter=0;iter<x.second;iter++){
                mul=mul*x.first;
            }
        }
    }
    if(vec.size()==0){
    cout<<1<<"\n";
    cout<<orN<<"\n";
    }
    else{
    cout<<Max<<"\n";
    for(ll i=1;i<Max;i++){
        cout<<MaxEle<<" ";
    }
    cout<<mul*MaxEle<<"\n";
    }
    ump.clear();
    vec.clear();
}
void solve(ll tc){
    ll N;
    while(tc--){
        cin>>N;
        ll limit=sqrt(N);
        vector<ll>s;
        recurse(N,s,limit);
    }    
}
void input(){
    ll T;
    cin>>T;
    solve(T);
}
int main(){
    input();
    return 0;
}