#include<bits/stdc++.h>
using namespace std;
void recurse(string &g,vector<int>&index,unordered_map<char,int>&ump,int &iter){
    if(iter==index.size()){
        cout<<g<<"\n";
        return;
    }
    for(auto x:ump){
        if(x.second!=0){
            ump[x.first]--;
            g[index[iter]]=x.first;
            iter++;
            recurse(g,index,ump,iter);
            iter--;
            ump[x.first]++;
        }
    }
    return ;
}
int main(){
   int T;
   cin>>T;
   while(T--){
        string s;
        cin>>s;
        vector<int>ind;
        unordered_map<char,int>ump;
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(c=='?'){
                ind.push_back(i);
                ump['0']++;
                ump['1']++;
            }
        }
        string g;
        int iter=0;
        recurse(s,ind,ump,iter);
   }
   return 0;
}