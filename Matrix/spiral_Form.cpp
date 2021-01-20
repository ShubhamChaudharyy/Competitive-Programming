#include<bits/stdc++.h>
using namespace std;
void solve(int arr[10][10],int R,int C){
    int minCol=0,minRow=0;
    int maxRow=R,maxCol=C;
    while(minRow<maxRow){
        int fixedRow=minRow;
        int i,j,k,l;
        for(i=minRow;i<maxCol;i++){
            cout<<fixedRow<<" "<<i<<"\n";
        }
        int fixedCol=maxCol-1;
        for(j=minRow+1;j<maxRow;j++){
            cout<<j<<" "<<fixedCol<<"\n";
        }
        fixedRow=maxRow-1;
        for(k=maxCol-2;k>=minCol;k--){
            cout<<fixedRow<<" "<<k<<"\n";
        }
        fixedCol=minCol;
        for(l=maxRow-2;l>=minRow+1;l--){
            cout<<l<<" "<<fixedCol<<"\n";
        }
        minCol++;minRow++;
        maxRow--;maxCol--;
    }
    
}
int main(){
    int arr[10][10];
    solve(arr,3,5);
}