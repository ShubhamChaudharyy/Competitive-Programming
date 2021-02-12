#include<bits/stdc++.h>
using namespace std;
int boolean[5][5]={{0}};
void debugArray(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<boolean[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void allWays(int r,int c,int iter){
    if(r<0 || c<0 || r>=5 || c>=5 || boolean[r][c]>0){
        return;
    }
    if(iter==25){
        boolean[r][c]=25;
        debugArray();
        boolean[r][c]=0;
        return;
    }
    boolean[r][c]=iter;
    allWays(r-2,c+1,iter+1);
    allWays(r-2,c-1,iter+1);
    allWays(r+1,c-2,iter+1);
    allWays(r-1,c-2,iter+1);
    allWays(r+2,c+1,iter+1);
    allWays(r+2,c-1,iter+1);
    allWays(r-1,c+2,iter+1);
    allWays(r+1,c+2,iter+1);
    boolean[r][c]=0;
    return;
}
int main(){
    int r=0,c=0;
    allWays(0,0,1);
}