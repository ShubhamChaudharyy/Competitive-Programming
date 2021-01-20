#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(ll tc){
    while(tc--){
       ll N;
       cin>>N;
       vector<ll>arr;
       ll preSum=0;
       for(ll i=0;i<N;i++){
           ll item;
           cin>>item;
           arr.push_back(item);
           preSum+=item; 
       }
       ll steps=0;
       ll newS=arr[0];
       for(ll i=1;i<N;i++){
           auto it=arr.begin();
           if(newS!=arr[i]){
               if(newS<preSum-newS){
                   arr.erase(it+i);
                   newS+=arr[i];
                   steps+=1;
               }
               else if(newS>=preSum-newS){
                   arr.erase(it+(i-1));
                   steps+=N-i-2;
                   break;
               }
           }
           else{
               preSum-=arr[i];
           }
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