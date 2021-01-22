#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<ll>>boolean(300,vector<ll>(300,0));
void reset(){
    boolean={{0}};
}
void debug2Darray(vector<vector<ll>>tempArr){
    for(auto x:tempArr){
        vector<ll>temp=x;
        for(ll c:temp){
            cout<<c<<" ";
        }
        cout<<"\n";
    }
}
void dfs(vector<vector<ll>>&grid,int r,int c){
    if(r<0 || c<0 || r==grid.size() || c==grid[0].size() || grid.size()==1 || boolean[r][c]==1){
        return;
    }
    if(grid[r][c]==0)
    grid[r][c]=2;
    boolean[r][c]++;
    dfs(grid,r-1,c);
    dfs(grid,r,c-1);
    dfs(grid,r+1,c);
    dfs(grid,r,c+1);
    return;
}
void solve(ll tc){
    while(tc--){
        ll N,M;
        vector<vector<ll>>arr;
        cin>>N>>M;
        for(ll i=0;i<N;i++){
            vector<ll>temp;
            for(ll j=0;j<M;j++){
                ll item;
                cin>>item;
                temp.push_back(item);
                }
            arr.push_back(temp);
        }
        ll maxRow=N-1,maxCol=M-1;
        ll minRow=0,minCol=0;
        for(ll j=minCol;j<=maxCol;j++){
            if(arr[minRow][j]==0){
                dfs(arr,minRow,j);
            }
        }
        for(ll m=minRow+1;m<=maxRow;m++){
            if(arr[m][maxCol]==0){
                dfs(arr,m,maxCol);
            }
        }
        for(ll n=maxCol-1;n>=minCol;n--){
            if(arr[maxRow][n]==0){
                dfs(arr,maxRow,n);
            }
        }
        for(ll l=maxRow-1;l>=minRow+1;l--){
            if(arr[l][minCol]==0){
                dfs(arr,l,minCol);
            }
        }
        debug2Darray(arr);
    }
}
void input(){
    ll T;
    cin>>T;
    solve(T);
}
int main(){
    input();
}