#include<bits/stdc++.h>
#define ll long long
using namespace std;
void fillUp(vector<ll>&temp,ll limit){
    for(int i=0;i<limit;i++){
        ll item;
        cin>>item;
        temp.push_back(item);
    }
}
bool comp(pair<int,int>a,pair<int,int>b){
    return a.first<b.first;
}
void solve(ll tc){
    while(tc--){
        ll N,K;
        cin>>N>>K;
        vector<ll>points,num;
        fillUp(num,N);
        fillUp(points,N);
        vector<pair<int,int>>final;
        ll Sum=0;
        for(int i=0;i<N;i++){
            Sum+=num[i];
            final.push_back({num[i],points[i]});
        }
        sort(final.begin(),final.end(),comp);
        vector<pair<int,int>>dp(Sum+1,{0,-1});
        for(int i=0;i<N;i++){
            for(int j=0;j<=Sum;j++){
                ll val=final[i].first;
                ll pts=final[i].second;
                ll dpBool=dp[j].first;
                ll dpPts=dp[j].second;
                if(i==0)
                    dp[j]={1,pts};
                else if(j==0)
                    dp[j]={1,0};
                else if(val>j)
                    continue;
                else if(val==j){
                    if(dpBool){}
                }
                else{
                    ll diff=
                }
            }
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