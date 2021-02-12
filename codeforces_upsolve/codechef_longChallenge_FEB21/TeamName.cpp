#include <bits/stdc++.h>
#define ll long long
using namespace std;
void debugger(string s,ll value){
	cout<<s<<" "<<value<<"\n";
}
int main() {
    ll N,T;
    cin>>T;
    while(T--){
        unordered_map<string,int>suf,all;
        unordered_map<char,int>pf;
        vector<string>suffix;
        vector<char>prefix;
        ll n;
        cin>>n;
        for(ll i=0;i<n;i++){
            string s;
            cin>>s;
            all[s]++;
            if(pf.count(s[0])==0){
                prefix.push_back(s[0]);
                pf[s[0]]++;
            }
            string rem=s.substr(1,s.length());
            if(suf.count(rem)==0){
                suffix.push_back(rem);
                suf[rem]++;
            }
        }
        ll tw=0;
        map<string,vector<char>>grp;
        vector<int>pfcount(26,0);
        vector<string>diff;
        for(char c:prefix){
            for(string g:suffix){
                string temp=c+g;
                if(all.count(temp)==0){
                    int code=int(c)-97;
                    tw++;
                    pfcount[code]++;
                    grp[g].push_back(c);
                    all[temp]++;
                }
            }
        }
        ll finalans=0;
        for(auto x:grp){
            vector<char>ic=x.second;
            ll testW=tw;
            for(char c:ic){ 
                int code=int(c)-97;
                testW=testW-pfcount[code]; 
                pfcount[code]--;
            }
            finalans+=2*testW;
            tw-=ic.size();
        }
    }
	return 0;
}
