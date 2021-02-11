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
	    stack<pair<ll,ll>>s;
		ll size,blds;
		cin>>size>>blds;
		vector<ll>hts;
		for(ll i=0;i<size;i++){
			ll item;
			cin>>item;
			hts.push_back(item);
		}
		ll iter=0;
		// 2 4 5 9 8 9
		while(blds){
			for(int i=iter;i<size;i++){
				if(hts[i]>=hts[i+1])
					continue;
				else{
					iter=i;
					hts[i]++;
					ll ntz=iter;
					while(ntz-1>=0 && hts[ntz-1]<hts[ntz])
						ntz--;
					iter=ntz;
				}
				blds--;
			}
		}
	} 
	return 0;
}
// ans-> 36 146 154 