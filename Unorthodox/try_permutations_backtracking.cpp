#include<bits/stdc++.h>
using namespace std;
void recurse(unordered_map<int,int>&hash,int places,vector<int>&s){
    if(s.size()==4)
    return;
    for(auto x: hash){
        hash[x.first]--;
        s.push_back(x.first);
        int left=places-1;
        recurse(hash,left,s);
        hash[x.first]++;
    }
}
int main(){
    int arr[4]={1,2,3,4};
    unordered_map<int,int>mp;
    for(int i=0;i<4;i++){
        mp[arr[i]]++;
    }
    int places=4;
    vector<int>str;
    recurse(mp,places,str);
}