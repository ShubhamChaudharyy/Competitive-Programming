#include<bits/stdc++.h>
#define ll long long
using namespace std;
void recurse(ll Num,stack<ll>que,ll limit){
    for(ll i=2;i<=limit;i++){
        if(Num%i==0){
            ll NewNum=Num/i;
            if(i%que.top()==0){
                que.push(i);
            }
            else 
            continue;
            recurse(NewNum,que,limit);
            s.pop();
        }
    }
}
void solve(ll tc){
    ll N;
    while(tc--){
        cin>>N;
        ll limit=sqrt(N);
        stack<ll>s;
        s.push(1);
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