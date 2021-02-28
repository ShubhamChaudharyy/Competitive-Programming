#include<bits/stdc++.h>
#define ll long long
using namespace std;
void rec(string s,ll n,ll limit,ll left,ll right){
    if(s.length()==limit){
        cout<<s<<"\n";
        return;
    }
    if(left<n)
        rec(s+"(",n,limit,left+1,right);
    if(right<left)
        rec(s+")",n,limit,left,right+1);
    return;
}
int main(){
    string s="";
    int n;
    cin>>n;
    ll l=0,r=0,index=0;
    rec(s,n,2*n,l,r);
}