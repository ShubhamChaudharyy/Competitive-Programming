#include<bits/stdc++.h>
#define ll long long
int c=0;
using namespace std;
int solve(string s,unordered_map<string,int>&ump,unordered_map<string,int>&dp){
    c++;
    if(s.length()==1){
        if(ump[s])
        return 1;
        else
        return 0;
    }
    string temp="";
    string recur="";
    ll ans=0;
    if(dp[s]){
        if(dp[s]==-1)
        return 0;
        else
        return 1;
    }
    for(int i=0;i<s.length();i++){
        temp=temp+s[i];
        recur=s.substr(i+1,s.length()+1);
        if(!ump[temp])
           continue;
        else if(ump[temp] && ump[recur])
            return 1;
        ans=ans+(ump[temp]*solve(recur,ump,dp));
        if(ans==0)
        dp[recur]=-1;
        else
        dp[recur]=1;
    }
    return ans;
}
int main(){
    ll T;
    vector<string>dict={"w","o","r","d","dum","maaro","dummaaro","ore","e"};
    unordered_map<string,int>dp;
    unordered_map<string,int>ump;
    for(string g:dict)
        ump[g]=1;
    string s="worde";
    cout<<solve(s,ump,dp)<<"\n";
    cout<<c<<"\n";
}