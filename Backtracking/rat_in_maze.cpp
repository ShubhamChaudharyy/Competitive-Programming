#include<bits/stdc++.h>
using namespace std;
int boolean[5][5]={{0}};
void findTrack(int maze[5][5],int r,int c,string psf){
    if(r<0 || c<0 || r==5 || c==5 || maze[r][c]==1 || boolean[r][c]==1)
    return;
    if(r==4 && c==4){
        cout<<psf<<"\n";
        return;
    }
    boolean[r][c]=1;
    findTrack(maze,r-1,c,psf+"T");
    findTrack(maze,r,c-1,psf+"L");
    findTrack(maze,r+1,c,psf+"D");
    findTrack(maze,r,c+1,psf+"R");
    boolean[r][c]=0;
}
int main(){
    int maze[5][5]={
        {0,0,1,1,0},
        {1,0,1,1,1},
        {1,0,1,1,1},
        {1,0,1,1,1},
        {1,0,0,0,0},
    };
    string psf="";
    findTrack(maze,0,0,psf);
    return 0;
}