#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>choices;
int grid[9][9] = {  {3, 0, 6, 5, 0, 8, 4, 0, 0},
                    {5, 2, 0, 0, 0, 0, 0, 0, 0},
                    {0, 8, 7, 0, 0, 0, 0, 3, 1},
                    {0, 0, 3, 0, 1, 0, 0, 8, 0},
                    {9, 0, 0, 8, 6, 3, 0, 0, 5},
                    {0, 5, 0, 0, 9, 0, 6, 0, 0},
                    {1, 3, 0, 0, 0, 0, 2, 5, 0},
                    {0, 0, 0, 0, 0, 0, 0, 7, 4},
                    {0, 0, 5, 2, 0, 6, 3, 0, 0}
                };
void display(int grid[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            cout<<grid[i][j]<<" ";
        cout<<"\n";
    } 
}
void reset(){
    choices[1]++;choices[2]++;choices[3]++;
    choices[4]++;choices[5]++;
    choices[6]++;choices[7]++;choices[8]++;choices[9]++;
}
bool isValid(int arr[9][9],int a,int b,int pos){
    for(int iter=0;iter<9;iter++){
        if(arr[a][iter]==pos)
        return false;
    }
    for(int iter=0;iter<9;iter++){
        if(arr[iter][b]==pos)
        return false;
    }
    int smi=(a/3)*3;
    int smj=(b/3)*3;
    for(int row=smi;row<smi+3;row++){
        for(int col=smj;col<smj+3;col++){
            if(arr[row][col]==pos)
            return false;
        }
    }
    return true;
}
void solve(int grid[9][9],int i,int j){
    int ni=0;
    int nj=0;
    if(i==9){
        display(grid);
        return;
    }
    if(j==8){
        ni=i+1;
        nj=0;
        reset();
    }
    else{
        ni=i;
        nj=j+1;
    }
    if(grid[i][j]!=0)
    solve(grid,ni,nj);
    else {
        for(auto x:choices){
            if(choices[x.first]){
                if(isValid(grid,i,j,x.first)){
                    grid[i][j]=x.first;
                    choices[x.first]--;
                    solve(grid,ni,nj);
                    grid[i][j]=0;
                    choices[x.first]++;
                }    
            }
        }
    }
    return;
}
int main(){
    solve(grid,0,0);
    return 0;
}