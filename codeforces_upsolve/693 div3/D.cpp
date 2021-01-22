#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(ll tc){
    while(tc--){
        ll N;
        priority_queue<int,vector<int>,greater<int>>odd,even;
        cin>>N;
        for(ll i=0;i<N;i++){
            ll item;
            cin>>item;
            if(item&1)
                odd.push(item);
            else
                even.push(item);
        }
        ll A=1,B=0;
        ll Sa=0,Sb=0;
        while(!even.empty() || !odd.empty()){
            if(A==1){
                if(even.empty() || even.top()<odd.top())
                    odd.pop();
                else if(even.top()>=odd.top()){
                    Sa+=even.top();
                    even.pop();
                }
            }
            else if(B==1){
                if(odd.empty() || even.top()>odd.top())
                    even.pop();
                else if(odd.top()>=even.top()){
                    Sb+=odd.top();
                    odd.pop();
                }
            }
        }
        if(Sa>Sb)
        cout<<"Alice \n";
        else if(Sa<Sb)
        cout<<"Bob \n";
        else
        cout<<"Tie \n";
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