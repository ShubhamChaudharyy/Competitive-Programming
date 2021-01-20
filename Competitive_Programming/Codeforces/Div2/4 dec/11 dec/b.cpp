#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(ll tc){
    while(tc--){
        ll M,N;
        cin>>M>>N;
        string A[M][N];
        ll up[M][N];
        for(ll i=0;i<M;i++){
            for(ll j=0;j<N;j++){
                cin>>A[i][j];
            }
        }
        ll left[M][N];
        ll right[M][N];
        ll count=0;
        ll count2=0;
        ll ans=0;
        for(ll i=0;i<M;i++){
            for(ll j=0;j<N;j++){
                if(A[i][j]=="*"){
                    count++;
                    left[i][j]=count;
                }
                else 
                count=0;
            }
            count=0;
            for(ll j=N-1;j>=0;j--){
                if(A[i][j]=="*"){
                    count2++;
                    left[i][j]=count2;
                }
                else 
                count2=0;
            }
            count2=0;
        }
        for(ll i=0;i<M;i++){
            for(ll j=0;j<N;j++){
                if(i==0 && A[i][j]=="*"){
                    up[i][j]=1;
                    ans+=1;
                }
                else if(A[i][j]=="*"){
                    ll prevBase=up[i-1][j];
                    ll currentBase=(min(left[i][j],right[i][j])*2)+1;
                    if(currentBase>prevBase){
                        prevBase+=3;
                        up[i][j]=prevBase-1;
                        ans+=prevBase;
                    }
                    else{
                        currentBase+=1;
                        up[i][j]=currentBase-1;
                    }
                }
            }
        }
    }
}
void input(){
    ll t;
    cin>>t;
    solve(t);
}
int main(){
    input();
    return 0;
}