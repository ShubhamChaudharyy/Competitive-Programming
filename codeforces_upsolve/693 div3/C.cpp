#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(ll tc){
    while(tc--){
        vector<int>arr;
        ll N;
        cin>>N;
        for(ll i=0;i<N;i++){
            ll item;
            arr.push_back(item);
        }
        vector<ll>dp(N,0);
        for(ll i=N-1;i>=0;i--){
            if(i+arr[i]<=N-1){
                ll jump=arr[i]+1;
                dp[i]+=arr[i]+dp[jump];
            }
            else{
                dp[i]+=arr[i];
            }
        }
        for(ll c:dp){
            cout<<c<<" ";
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
}