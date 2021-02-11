#include<bits/stdc++.h>
#define ll long long
using namespace std;
void display(vector<int>a){
    for(int c:a){
        cout<<c<<" ";
    }
    cout<<"\n";
}
void allSubsets(int start,vector<int>all,vector<int>sf){
    if(sf.size()>0){
        display(sf);
    }
    for(int i=start;i<all.size();i++){
        sf.push_back(all[i]);
        allSubsets(i+1,all,sf);
        sf.pop_back();
    }
    return;
}
int main(){
    vector<int>ele={1,2,3,4};
    vector<int>temp;
    allSubsets(0,ele,temp);
}