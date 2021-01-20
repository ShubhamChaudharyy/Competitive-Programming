#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int>ump;
unordered_map<string,vector<string>>dp;
vector<string>solve(string s,string prev){
    if(s.length()==0){
        vector<string>vec={""};
        return vec;
    }
    string temp="";
    string rem="";
    vector<string>res;
    if(dp.count(s)){
        vector<string>g;
        vector<string>t=dp[s];
        for(string c:t){
            g.push_back(temp+" "+c);
        }
        return g;
    }
    for(int i=0;i<s.length();i++){
        temp=s.substr(0,i+1);
        rem=s.substr(i+1,s.length()+1);
        if(ump[temp]){
            vector<string>vec=solve(rem,temp+" ");
            for(string str:vec){
                res.push_back(temp+" "+str);
            }
        }
    }
    dp[s]=res;
    return res;
}
int main(){
    string s="pineapplepenapple";
    vector<string>vec={"apple", "pen", "applepen", "pine", "pineapple"};
    for(string c:vec){
        ump[c]++;
    }
    vector<string>ans=solve(s,"");
    for(string c:ans){
        cout<<c<<" ";
        cout<<"\n";
    }
    cout<<"\n";
    for(auto s:dp){
        vector<string>temp=s.second;
        cout<<s.first<<":";
        for(string c:temp){
            cout<<c<<" ";
        }
        cout<<"\n";
    }
}