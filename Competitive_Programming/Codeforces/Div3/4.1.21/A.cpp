#include<bits/stdc++.h>
#define ll long long
using namespace std;
int recurse(ll L,ll B){
    int ans=1;
    while(L%2==0 || B%2==0){
        if(L%2==0){
            L=L/2;
            ans=ans*2;
        }
        else if(B%2==0){
            B=B/2;
            ans=ans*2;
        }
    }
    return ans;
}
void solve(ll tc){
    while(tc--){
        ll X,Y,K;
        cin>>X>>Y>>K;
        ll ans=recurse(X,Y);
        if(ans>=K){
            cout<<"YES \n";
        }
        else
        {
            cout<<"NO \n";
        }
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