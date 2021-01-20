#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve(ll t){
    while(t--){
        ll N;
        string s;
        cin>>s;
        cin>>N;
        int left=0,right=0;
        vector<char>ans;
        int Max=INT_MIN;
        unordered_map<char,int>ump;
        while(right<=s.length()-1){
            char ch=s[right];
            ump[ch]++;
            if(ump.size()>N){
                Max=max(right-left,Max);
                while(ump.size()>N){
                    auto it=ans.begin();
                    ans.erase(it+1);
                    char temp=s[left];
                    ump[temp]--;
                    left++;
                }
            }
            if(right==s.length()-1)
            Max=max(Max,right-left);
            ans.push_back(ch);
            right++;
        }
        cout<<Max<<"\n";
    }
}
void input(){
    ll tc;
    cin>>tc;
    solve(tc);
}
int main() {
	input();
	return 0;
}