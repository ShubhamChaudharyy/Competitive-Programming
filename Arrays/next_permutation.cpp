#include<bits/stdc++.h>
#define ll long long
using namespace std;
class permutation{
    ll T;
    public:
    permutation(){
        ll tests;
        cin>>tests;
        this->T=tests;
        solve();
    }
    void solve(){
        ll i,item,N;
        while(this->T--){
            cin>>N;
            vector<ll>arr;
            for(i=0;i<N;i++){
                cin>>item;
                arr.push_back(item);
            } 
            i=N-2;
            while(arr[i]>=arr[i+1] && i>=0) i--;
            ll j=N-1;
            while(arr[j]<arr[i] && j>=0) j--;
            if(j>0){
                swap(arr,i,j);
                reverse(arr,N-1,i+1);
            }
            else {
                reverse(arr,N-1,0);
            }
            for(ll i=0;i<N;i++)
            cout<<arr[i];
            cout<<"\n";
            }
    }
    void swap(vector<ll>&arr3,ll a1,ll a2){
        ll temp=arr3[a1];
        arr3[a1]=arr3[a2];
        arr3[a2]=temp;
    }
    void reverse(vector<ll> &arr2,ll end, ll start){
        while(end>=start){
            ll temp=arr2[start];
            arr2[start]=arr2[end];
            arr2[end]=temp;
            start++;end--;
        }
    }
};
int main(){
    permutation p;
    return 0;
}