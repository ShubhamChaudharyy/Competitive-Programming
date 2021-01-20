#include<bits/stdc++.h>
using namespace std;
int countk=0;
void permute(vector<int>&s,map<int,int>&map){
    if(s.size()==4){
        for(int x:s)
        cout<<x<<" ";
        cout<<"\n";
        return ;
    }
    for(auto x:map){
        if(x.second!=0){
        int indiv=x.first;
        map[x.first]--;
        s.push_back(x.first);
        permute(s,map);
        map[indiv]++;
        int pos=s.size()-1;
        s.erase(s.begin()+pos);
        }
    }
}
int main(){
    int arr[3]={1,2,3};
    map<int,int>ump;
    for(int i=0;i<4;i++){
        ump[0]++;
        ump[1]++;
    }
    vector<int>s;
    permute(s,ump);
    return 0;
} 