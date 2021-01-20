#include<bits/stdc++.h>
using namespace std;
int FR=3,FC=5;
int boolean[3][5]={{0}};
void display(vector<pair<int,int>>ans){
    for(auto x:ans){
        cout<<x.first<<" "<<x.second<<" ";
    }
    cout<<"\n";
}
void solve(int mat[3][5],int r,int c,vector<pair<int,int>>psf){
    if(r<0 || r==FR || c==FC || c<0 || mat[r][c]==1)
        return;
    if(boolean[r][c])
        return;
    if(r==FR-1 && c==FC-1){
        cout<<"came here "<<"\n";
        display(psf);
        return;
    }
    boolean[r][c]=1;
    vector<pair<int,int>>t1=psf;
    t1.push_back({r-1,c});
    solve(mat,r-1,c,t1);
    
    vector<pair<int,int>>t2=psf;
    t2.push_back({r,c-1});
    solve(mat,r,c-1,t2);
    
    vector<pair<int,int>>t3=psf;
    t3.push_back({r+1,c});
    solve(mat,r+1,c,t3);
    
    vector<pair<int,int>>t4=psf;
    t4.push_back({r,c+1});
    solve(mat,r,c+1,t4);
    
    boolean[r][c]=0;
     
    return ;
}
int main(){
    int mat[3][5]={
        {0,0,0,1,1},
        {0,1,0,0,0},
        {0,0,0,0,0}
    };
    vector<pair<int,int>>psf;
    solve(mat,0,0,psf);
    return 0;
}