#include<bits/stdc++.h>
using namespace std;
vector<string>solve(int num){
    if(num==1){
        vector<string>temp;
        temp.push_back("0");
        temp.push_back("1");
        return temp;
    }
    num=num-1;
    vector<string>main=solve(num);
    vector<string>ans;
    vector<string>rev;
    int Nth=main.size();
    for(int i=0;i<main.size();i++){
        string s1=main[i];
        string s2=main[Nth-i-1];
        s1="0"+s1;
        s2="1"+s2;
        ans.push_back(s1);
        rev.push_back(s2);
    }
    for(int i=0;i<rev.size();i++){
        ans.push_back(rev[i]);
    }
    return ans;
}
void input(){
    int N;
    cin>>N;
    vector<string>A;
    A=solve(N);
    for(string x:A)
    cout<<x<<" ";
}
int main(){
    input();
    return 0;
}