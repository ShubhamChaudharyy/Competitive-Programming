#include<bits/stdc++.h>
using namespace std;
int limit=5;
void partition(int curr,map<int,vector<int>>ans,int sf){
     if(curr==5){
         if(ans.size()==3){
             for(auto x:ans){
                 vector<int>temp=x.second;
                 cout<<"( ";
                 for(int c:temp)
                 cout<<c<<" ";
                 cout<<")";
             }
             cout<<"\n";
         }
         return;
     }
     for(int i=0;i<3;i++){
         if(ans[i].size()>0){
             ans[i].push_back(curr);
             partition(curr+1,ans,sf);
             ans[i].pop_back();
         }
         else{
             ans[i].push_back(curr);
             partition(curr+1,ans,sf+1);
             ans[i].pop_back();
             break;
         }
     }
     return;
}
int main(){
    map<int,vector<int>>sets;
    int sf=0;
    int i=0;
    partition(1,sets,sf);
}