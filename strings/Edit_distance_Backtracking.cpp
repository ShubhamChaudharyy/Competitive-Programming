#include<bits/stdc++.h>
using namespace std;
string a="ABC",b="DC";
int Min=INT_MAX;
int func(int i,int j){
    if(j>=b.size()){
        int res=abs(j-i)+1;
        return res;
    }
    if(i>=a.size()){
        int res=abs(j-i)+1;
        return res;
    }
    if(a[i]==b[j]){
        i++;j++;
        func(i,j);
    }
    else{
        int Ins=func(i,j+1);
        int Del=func(i+1,j);
        int rep=func(i+1,j+1);
        Min=min(Ins,min(Del,rep));
    }
    return Min;
}
int main(){
 cout<<func(0,0);
}