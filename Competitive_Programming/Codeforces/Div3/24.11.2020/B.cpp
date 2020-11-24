#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(ll tc){
    while(tc--){
        ll N;
        cin>>N;
        vector<ll>arr;
        unordered_map<ll,ll>ump;
        for(ll i=0;i<N;i++){
            ll item;
            cin>>item;
            arr.push_back(item);
            ump[item]++;
        }
        ll Min=INT_MAX,index=-1;
        for(ll i=0;i<N;i++){
            ll ele=arr[i];
            if(ump[ele]==1){
                if(ele<Min){
                    index=i+1;
                    Min=ele;
                }     
            }
        }
        if(index==-1)
        cout<<-1<<"\n";
        else
        cout<<index<<"\n";
        ump.clear();
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