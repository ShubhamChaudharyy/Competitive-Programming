#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(ll tc){
    while(tc--){
        ll N;
        cin>>N;
        vector<ll>arr;
        ll sum=0;
        for(ll i=0;i<N;i++){
            ll item;
            cin>>item;
            sum+=item;
            arr.push_back(item);
        }
        vector<int>factors;
        for(ll i=1;i<sqrt(sum);i++){
            if(sum%i==0){
                factors.push_back(i);
                ll check = sum/i;
                if(check<=N){
                    factors.push_back(check);
                }
                else if(i<=N)
                factors.push_back(check);
            }
        }
        ll Min=INT_MAX;
        for(ll c:factors){
            cout<<c<<" ";
        }
        cout<<endl;
        for(ll c:factors){
            ll sum=arr[0];
            ll target=c;
            ll steps=0;
            ll exc=0;
            for(ll i=1;i<N;i++){
                if(sum>target){
                    exc=1;
                    break;
                }
                else if(sum==target){
                    sum=0;
                    sum=arr[i];
                }
                else
                {
                    sum+=arr[i];
                    steps++;
                }
            }
            if(exc==0)
            Min=min(steps,Min);
            cout<<steps<<"\n";
        }
        cout<<Min<<"\n";
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