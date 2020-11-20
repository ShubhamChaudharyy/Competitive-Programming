#include <bits/stdc++.h> 
#define ll long long
using namespace std;
void permute( string s1,string s2 ){
    if(s1.length()==0){
        string s3=s1+s2;
        if(s3.length()==2)
        cout<<s3<<"\n";
        return ;
    }
    string op1=s2;
    string op2=s2;
    op2.push_back(s1[0]);
    s1.erase(s1.begin()+0);
    permute(s1,op1);
    permute(s1,op2);
}
int main(){
    string ip="abcd";
    string op="";
    permute(ip,op);
}