#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(ll tc){
    while(tc--){
        int N;
        cin>>N;
        for(int i=1;i<=N;i++){
            if(i==N)
            cout<<1<<" ";
            else
            cout<<i+1<<" ";
        }
        cout<<"\n";
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