#include<bits/stdc++.h>
#define ll long long
using namespace std;
vois solve(ll tc){
    while(tc--){
        ll N;
        cin>>N;
        vector<ll>a;
        for(ll i=0;i<N;i++){
            ll item;
            cin>>item;
            a.push_back(item);
        }
        vector<ll>ans;
        ll i=0,j=N-1;
        while(i<j){
            ans.push_back(a[i]);
            ans.push_back(a[j]);
            i++;j--;
            if(i==j)
            ans.push_back(a[i]);
        }
        for(ll x:ans)
        cout<<x<<" ";
        cout<<"\n";
    }
}
void input(){
    ll T;
    solve(T);
}
int main(){
    input();
    return 0;
}