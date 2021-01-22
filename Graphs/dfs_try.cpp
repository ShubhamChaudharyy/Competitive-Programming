#include<bits/stdc++.h>
#define ll long long
using namespace std;
int boolean[7][7]={0};
void recurse(int mat[7][7],int r,int c){
    if(r<0 || c<0 || r==7 || c==7 || mat[r][c]==0 || boolean[r][c]==1){
        cout<<"stpped at"<<"\n";
        return;
    }
    if(mat[r][c]==1)
    mat[r][c]=2;
    if(r==6 && c==6)
    return;
    boolean[r][c]=1;
    recurse(mat,r,c-1);
    recurse(mat,r+1,c);
    recurse(mat,r-1,c);
    recurse(mat,r,c+1);
    return;
}
void solve(int mat[7][7],int r,int c){
    int num=0;
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            if(mat[i][j]==1 ){
                mat[i][j]=2;
                recurse(mat,i,j);
                boolean[7][7]={0};
                num++;
            }
        }
    }
    cout<<num<<"\n";
}
int main(){
    ll T;
    int matrix[7][7]={
        {1,1,1,1,1,1,1},
        {0,0,0,0,0,0,1},
        {1,1,1,1,1,0,1},
        {1,0,0,0,1,0,1},
        {1,0,1,0,1,0,1},
        {1,0,1,1,1,0,1},
        {1,1,1,1,1,1,1}
    };
    solve(matrix,0,0);
    return 0;
}