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
	    ll n,k;
	    vector<ll>arr;
	    cin>>n>>k;
	    ll Max=INT_MIN,Min=INT_MAX;
	    // 1 2 3 4
	    // 0 1 2 3
	    vector<ll>ps;
	    ll pfs=0;
	    for(ll i=0;i<n;i++){
	        ll item;
	        cin>>item;
	        arr.push_back(item);
	    }
	    sort(arr.begin(),arr.end());
	    for(ll c:arr){
	        pfs+=c;
	        ps.push_back(pfs);
	    }
	    ll ans=0;
	    ll ssf=0;
	    ll i=0;
        for(int c:arr){
            cout<<c<<"\n";
        }
	    while(i<n){
	        ll pos = upper_bound(arr.begin(),arr.end(),arr[i]+k)-arr.begin();
	        if(pos==n)
	        break;
	        ll sm = upper_bound(arr.begin(),arr.end(),arr[i])-arr.begin();
	        ll rngsum = ps[n-1]-ps[pos-1];
	        ll chng = rngsum-((n-pos)*(arr[i]+k));
	        if( (sm-i)*arr[i] >= chng ){
	            cout<<arr[pos]<<" got big fish... no need to run now"<<"\n";
                ans+=chng;
	            break;
	        }
            cout<<arr[i]<<" removed "<<"\n";
	        ans+=(sm-i)*arr[i];
	        i=sm;
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}