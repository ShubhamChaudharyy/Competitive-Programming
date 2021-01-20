#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve(ll tc){
    while(tc--){
        ll N;
        cin>>N;
        vector<ll>vec;
        ll item;
        for(ll i=0;i<N;i++){
            cin>>item;
            vec.push_back(item);
        }
        ll init=1;
        ll Max=INT_MIN,MaxF1=INT_MIN;
        ll Min=INT_MAX,MaxF2=INT_MIN;
        ll prevMax=vec[0];
        ll prevMin=vec[0];
        for(ll i=1;i<vec.size();i++){
            if(vec[i]==0){
                init=1;
                Min=1;
                Max=1;
                prevMax=1;
                prevMin=1;
            }
            else{
                Max=(Max,prevMax*vec[i]);
                Max=(Max,prevMin*vec[i]);
                Min=(Min,prevMin*vec[i]);
                Min=(Min,prevMax*vec[i]);
                prevMax=Max;
                prevMin=Min;
                MaxF1=max(MaxF1,Max);
            }
        }
        Max=INT_MIN;
        Min=INT_MAX;
        MaxF2=INT_MIN;
        prevMax=vec[0];
        prevMin=vec[0];
        for(ll i=vec.size()-1;i>=0;i--){
            if(vec[i]==0){
                init=1;
                Min=1;
                Max=1;
                prevMax=1;
                prevMin=1;
            }
            else{
                Max=(Max,prevMax*vec[i]);
                Max=(Max,prevMin*vec[i]);
                Min=(Min,prevMin*vec[i]);
                Min=(Min,prevMax*vec[i]);
                prevMax=Max;
                prevMin=Min;
                MaxF2=max(MaxF2,Max);
            }
        }
        cout<<max(MaxF2,MaxF1)<<"\n";
    }
}
void input(){
    ll T;
    cin>>T;
    solve(T);
}
int main() {
    input();
	return 0;
}