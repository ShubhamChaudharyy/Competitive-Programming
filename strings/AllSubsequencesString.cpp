#include<bits/stdc++.h>
using namespace std;
void recurse(string s1,string s2,vector<string>&vec){
    if(s2.length()==0){
        vec.push_back(s1+s2);
        return;
    }
    string output1="";
    string output2=""+s2[0];
    char ch=s2[0]-97;
    s2.erase(ch);
    recurse(output1,s2,vec);
    vector<string>temp;
    for(string s:temp){
        string sx=output2+s;
        temp.push_back(sx);
    }
    for(string x:temp)
    vec.push_back(x);
    return;
}

int main(){
    string main="abc";
    vector<string>vec;
    string s1="";
    recurse(s1,main,vec);
    for(string c:vec)
    cout<<c<<" ";
    cout<<"\n";
}