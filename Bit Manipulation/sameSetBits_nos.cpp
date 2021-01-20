#include<bits/stdc++.h>
using namespace std; 
void recurse(vector<int>a1,int &ans){
    
}
int main(){
    int n;
    cin>>n;
    vector<int>bin;
    while(n!=0){
        bin.push_back(n%2);
        n=n/2;
    }
    reverse(bin.begin(),bin.end());
    vector<int>bin2=bin;
    int ans=0;
    for(int x:bin)
    cout<<x<<" ";
    cout<<"\n";
    recurse(bin,ans);
    return 0;
}