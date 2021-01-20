#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(ll tc){
    while(tc--){
        vector<ll>ans;
        ll X;
        cin>>X;
        if(X>45)
        cout<<-1<<"\n";
        else if(X<=9 )
        cout<<X<<"\n";
        else{
            ll rp=9;
            stack<ll>s;
            while(X!=0){
                X=X-rp;
                s.push(rp);
                rp--;
                if(X<=rp)
                {s.push(X);break;}
            }
            ll po=s.size()-1;
            ll sum=0;
            while(!s.empty()){
                sum+=pow(10,po)*s.top();
                po--;
                s.pop();
            }
            cout<<sum<<"\n";
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