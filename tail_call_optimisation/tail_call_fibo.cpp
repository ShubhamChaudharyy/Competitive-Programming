#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>ump;
void fibo(int f,int s,int n,int asf){
    if(n==0){
        cout<<asf;
        return;
    }
    fibo(s,f+s,n-1,f+s);
    return;
}
void solve(int num){
    fibo(0,1,num-2,0);
}
int main(){
    solve(9);
}