#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool comp(ll a,ll b){
    return a>=b;
}
int main() {
	ll t;
	cin>>t;
	while(t--){
	    ll xf,yf;
		cin>>xf>>yf;
		unordered_map<char,int>ump;
		string s;
		cin>>s;
		ll tx,ty;
		for(int i=0;i<s.length();i++){
			char ch=s[i];
			if(ch=='R')
			tx+=1;
			else if(ch=='L')
			tx-=1;
			else if(ch=='U')
			ty+=1;
			else if(ch=='D')
			ty-=1;
			ump[ch]++;
		}
		ll deficit_X=xf-tx;
		ll deficit_Y=yf-ty;
		ll Xcan=0,Ycan=0;
		if(deficit_X>0){
			if(ump['L']>=deficit_X)
			Xcan=1;
		}
		if(deficit_X<0){
			if(ump['R']>=abs(deficit_X))
			Xcan=1;
		}
		if(deficit_Y>0){
			if(ump['D']>=deficit_Y)
			Ycan=1;
		}
		if(deficit_Y<0){
			if(ump['U']>=abs(deficit_Y))
			Xcan=1;
		}
		if(Xcan || Ycan || (xf==tx && yf==ty))
		cout<<"YES \n";
		else
		cout<<"NO \n";
	}
	return 0;
}
// ans-> 36 146 154 