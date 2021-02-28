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
                    diff.push_back(temp);
                }
            }
        }
        ll finalans=0;
        if(diff.size()==0){
            cout<<0<<"\n";
            continue;
        }
        for(int i=0;i<diff.size()-1;i++){
            for(int j=i+1;j<diff.size();j++){
                char cpf1=diff[i][0],cpf2=diff[j][0];
                string csuf1=diff[i].substr(1,diff[i].length()),csuf2=diff[j].substr(1,diff[j].length());
                string tch1=cpf1+csuf2;string tch2=cpf2+csuf1;
                if(all.count(tch1)>0 && all.count(tch2)>0)
                    finalans+=2;
            }
        }
        cout<<finalans<<"\n";
    }
	return 0;
}
