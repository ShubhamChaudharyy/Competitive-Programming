#include<bits/stdc++.h>
using namespace std;
void solve(int rows,int col){
    string dp[1000][1000]={{""}};
    int half=rows/2;
    if(rows&1)
    half++;
    vector<string>key;
    for(int i=0;i<half;i++){
        string ele="";
        if(i&1)
        ele="O";
        else
        ele="X";
        key.push_back(ele);
    }
    for(int i=0;i<half;i++){
        for(int j=0;j<col;j++){
            if(i+j<=col-1){
                int Min=min(i,j);
                string ch=key[Min];
                dp[i][j]=ch;
                dp[rows-i-1][j]=ch;
            }
            else{
                int Max=max(i,j);
                string ch=key[col-1-Max];
                dp[i][j]=ch;
                dp[rows-i-1][j]=ch;
            }
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<col;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main(){
    int m,n;
    cin>>m>>n;
    solve(m,n);
    return 0;
}