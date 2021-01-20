#include<bits/stdc++.h>
using namespace std;
void computeZ(string s){
    int left=0,check=1,right=0,i=1,max=0,incL=0,incR=0;
    vector<int>Z(s.length(),0);
    while(i<s.length()){
        if(i<right){
            int mi=i-left;
            if(s[mi]+i-1<right){
                Z[i]+=Z[mi];check=0;incL=0;incR=0;
            }
            else{
                incR=right-i+1;incL=incR;check=1;
                Z[i]+=right-i+1;
            }
        }
        if(i+incR>=s.length()){
            right=s.length()-1;left=i;
            continue;
        }
        max=0;
        while(check==1 && s[incL]==s[i+incR]){
            max++;incR++;incL++;
            right=i+max-1;
            left=i;
            Z[i]+=max;
            if(i+incR>=s.length())
            break;
        }
        i++;
    }
}
int main(){
    string s="ohohohoh";
    computeZ(s);
}