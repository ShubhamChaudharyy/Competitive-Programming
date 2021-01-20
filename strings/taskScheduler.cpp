#include<bits/stdc++.h>
using namespace std;
class comp{
    public:
    bool operator()(pair<int,char>a,pair<int,char>b){
        return (a.first>b.first);
    }
};
void solve(string s,int n){
    unordered_map<char,int>prev;
    priority_queue<pair<int,char>,vector<pair<int,char>>,comp>pq;
    map<char,int,comp>main;
    vector<int>chars(26,0);
    for(int i=0;i<)
    for(int i=0;i<26;i++){
        if(chars[i]>0){
            if(chars[i]>(s.length()+1)/2)
            return "";
            else{
                char ch=97+i;
                pq.push({chars[i],ch});
            }
        }
    }
    string ans="";
    int ansLen=0;
    while(!pq.empty()){
    }
    cout<<ansLen<<"\n";
}
int main(){
    string s="absbabcbabb";
    int n=1;
    solve(s,n);
    return 0; 
}