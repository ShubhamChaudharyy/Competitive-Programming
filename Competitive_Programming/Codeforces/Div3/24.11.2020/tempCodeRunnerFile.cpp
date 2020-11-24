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
        vector<ll>unq;
        for(ll i=0;i<N-1;i++){
            if(arr[i]!=arr[i+1]){
                unq.push_back(arr[i]);
            }
            if(i==N-2){
                unq.push_back(arr[i+1]);
            }
        }
        if(ump.size()==N){
            cout<<1<<"\n";
        }
        else if(ump.size()==1 || N==0)
        cout<<0<<"\n";
        else {
            ump.clear();
            for(ll i=0;i<unq.size();i++){
                ll item=unq[i];
                ump[item]++;
            }
            ll Min=INT_MAX;
            for(auto x:ump){
                ll inc=x.second;
                if(x.first==unq[0])
                    inc--;
                if(x.first==unq[unq.size()-1])
                    inc--;
                Min=min(Min,inc+1);    
            }
            cout<<Min<<"\n";
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