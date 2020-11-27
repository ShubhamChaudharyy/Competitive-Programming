#include<bits/stdc++.h>
using namespace std;
vector<string>solve(int num,vector<string>bin){
    if(num==1){
        bin.push_back("0");
        bin.push_back("1");
        return bin;
    }
    int newnum=num-1;
    vector<string>New=solve(newnum,bin);
    vector<string>New2;
    int len=New.size();
    vector<string>B;
    for(int iter=0;iter<len;iter++){
        string s1="0"+New[iter];
        string s2="1"+New[len-1-iter];
        B.push_back(s1);
        New2.push_back(s2);
    }
    for(int i=0;i<len;i++){
        string item=New2[i];
        B.push_back(item);
    }
    return B;
}

int main(){
    int N=3;
    vector<string>s;
    vector<string>A=solve(N,s);
    for(string x:A){
    stringstream toint(x);
    toint>>x;
    cout<<x<<"\n";
    }
    return 0;
}