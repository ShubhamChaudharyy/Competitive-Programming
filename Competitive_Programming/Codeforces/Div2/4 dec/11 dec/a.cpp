#include<bits/stdc++.h>
#define ll long long
using namespace std;
 string pal(ll K){
     string s="";
     for(ll i=0;i<K;i++){
         s=s+"a";
     }
     return s;
 }
 void solve(ll tc){
     while(tc--){
        ll N,K;
        cin>>N>>K;
        string s2="";
        for(ll i=0;i<N-K;i++){
            int j=i%3;
            if(i==0){
                s2+="b";
            }   
            else if(i==1){
                s2+="c";
            } 
            else if(i==2){
                s2+="a";
            }
        }
        string s1=pal(K);
        for(ll i=0;i<N-K;i++){
            s1+=s2[i];
        }
        cout<<s1<<"\n";
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