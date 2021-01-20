#include<bits/stdc++.h>
using namespace std;
void computepi(vector<int>&pi,string p){
    int j=0;
    for(int i=1;i<p.length();i++){
        if(j>0 && p[i]!=p[j]){
            j=pi[j-1];
        }
        if(p[i]==p[j]){
            j++;
        }
        pi[i]=j;
    }
}
void solve(string s,string p){
    vector<int>pi(p.length(),0);
    computepi(pi,p);
    for(int c:pi){
        cout<<c<<" ";
    }
    int i=0,j=0;
    while(i<s.length()){
        if(j==pi.size()){
            cout<<"pattern found at"<<i-pi.size()<<"\n";
            j--;
            j=pi[j];
        }
        while(j>0 && s[i]!=p[j]){
            j=pi[j];
        }
        if(s[i]==p[j]){
            j++;
        }
        i++;
    }
}
int main(){
    string s="abababaabaac";
    string pat="abaa";
    solve(s,pat);
}