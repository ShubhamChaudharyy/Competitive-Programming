#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(ll tc){
    while(tc--){
        ll n,m,item;
        cin>>n>>m;
        unordered_map<ll,ll>left,bottom;
        for(ll i=0;i<n;i++){
            cin>>item;
            bottom[item]++;
        }
        for(ll i=0;i<n;i++){
            cin>>item;
            left[item]++;
        }
        ll answer=0;
        for(auto x: left){
            if(bottom[x.first]!=0){
                answer++;
            }
        }
        cout<<answer<<"\n";
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