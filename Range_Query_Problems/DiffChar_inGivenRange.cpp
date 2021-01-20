#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(ll t){
    while(t--){
        string s;
        cin>>s;
        vector<vector<int>>alphas(26);
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            alphas[ch-'a'].push_back(i+1);
        }
        ll Q;
        cin>>Q;
        while(Q--){
            ll L,R;
            cin>>L>>R;
            ll diff=0;
            for(int i=0;i<26;i++){
                vector<int>temp=alphas[i];
                int low=0,high=temp.size();
                while(low<=high){
                    int mid=(low+high)/2;
                    if(temp[mid]>=L && temp[mid]<=R){
                        diff++;
                        break;
                    }
                    else if(temp[mid]<L){
                        low=mid+1;
                    }
                    else if(temp[mid]>R){
                        high=mid-1;
                    }
                }
            }
            cout<<diff<<"\n";
        }    
    }   
}
void input(){
    ll tc;
    cin>>tc;
    solve(tc);
}
int main(){
    input();
    return 0;
}