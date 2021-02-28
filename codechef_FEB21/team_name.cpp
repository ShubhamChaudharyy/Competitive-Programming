#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll N,T;
    cin>>T;
    while(T--){
        ll N;
        unordered_map<string,vector<char>>suffix;unordered_map<char,int>dp;
        unordered_map<int,string>indexToString;
        unordered_map<string,int>stringToIndex;
        cin>>N;
        ll iter=0;
        vector<string>arr;
        for(ll i=0;i<N;i++){
            string str;
            cin>>str;
            arr.push_back(str);
            string remaining_string=str.substr(1,str.length());
            if(stringToIndex.count(remaining_string)==0){
                indexToString[iter]=remaining_string;
                stringToIndex[remaining_string]=iter;
                iter++;
            }
            suffix[remaining_string].push_back(str[0]);
        }
        vector<vector<int>>mat(suffix.size(),vector<int>(26,0));
        for(ll i=0;i<N;i++){
            string str=arr[i];
            dp[str[0]]++;
            string remaining_string=str.substr(1,str.length());
            ll asky_Code=int(str[0])-97;
            mat[stringToIndex[remaining_string]][asky_Code]++;
        }
        ll ans=0;
        if(dp.size()==1 || suffix.size()==1){
            cout<<0<<"\n";
            continue;
        }
        for(ll i=0;i<suffix.size()-1;i++){
            for(ll j=i+1;j<suffix.size();j++){
                ll minus=0,plus=0;
                for(char c:suffix[indexToString[i]]){
                    char present_char=c;
                    if(mat[j][int(c)-97])
                    minus++;
                    else
                    plus+=suffix[indexToString[j]].size();
                }
                if(plus>0){
                    ans+=(plus-(minus*(suffix[indexToString[i]].size()-minus)));
                }
            }
        }
        cout<<2*ans<<"\n";
    }
	return 0;
}
