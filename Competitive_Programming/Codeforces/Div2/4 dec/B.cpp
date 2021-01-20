#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(ll tc){
    ll N;
    while(tc--){
        cin>>N;
        vector<ll>vec;
        for(ll i=0;i<N;i++){
            ll item;
            cin>>item;
            vec.push_back(item);
        }
        ll steps=0;
        ll Max=INT_MIN;
        for(ll i=N-1;i>=1;i--){
            if(i!=N-1){
            Max=max(Max, abs(vec[i]-vec[i-1]) + abs( vec[i+1] - vec[i]) - abs( vec[i-1] - vec[i+1] ) );
            }
            steps+=abs(vec[i]-vec[i-1]);
        }
        ll Max2=max(abs(vec[1]-vec[0]),abs(vec[N-1]-vec[N-2]));
        Max=max(Max,Max2);
        cout<<steps-Max<<"\n";
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