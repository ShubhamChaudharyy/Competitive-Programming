// given jobs and hours associated with them , divide them into k workers so that worker getting maximum jobs hours have as minimum as job hours
#include<bits/stdc++.h>
using namespace std;
int gMax=INT_MAX;
    void calc(unordered_map<int,int>ump){
        for(auto x:ump){
            cout<<x.first<<" "<<x.second<<"\n"; 
        }
        int Max=INT_MIN;
        for(auto x:ump)
            Max=max(Max,x.second);
        gMax=min(gMax,Max);
    }
void recurse(int start,int tsets,vector<int>hours,unordered_map<int,int>sets){
    if(start==hours.size()){
        calc(sets);
        return;
    }
    for(int i=0;i<tsets;i++){
        if(sets[i]+hours[start]<gMax){
                if(sets[i]==0){
                    sets[i]+=hours[start];
                    recurse(start+1,tsets,hours,sets);
                    sets[i]-=hours[start];
                    break;
                }
                else{
                    sets[i]+=hours[start];
                    recurse(start+1,tsets,hours,sets);
                    sets[i]-=hours[start];
                }
            }
    }
    return;
}
int main(){
    unordered_map<int,int>ump;
    vector<int>hours={31,22,13,12,11,9};
    int k=3;
    for(int i=0;i<k;i++)
        ump[i]=0;
    recurse(0,k,hours,ump);
}