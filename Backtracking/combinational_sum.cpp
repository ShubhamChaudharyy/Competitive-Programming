#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>final_ans;
int target=14;
void display(vector<vector<int>>vec){
    for(auto x:vec){
        for(int c:x){
            cout<<c<<" ";
        }
        cout<<"\n";
    }
}
void cs(int start,vector<int>all,vector<int>sf,int sum){
    if(sum>=target){
        if(sum==target){
            final_ans.push_back(sf);        
        }
        return;
    }
    for(int i=start;i<all.size();i++){
        sum+=all[i];
        sf.push_back(all[i]);
        cs(i,all,sf,sum);
        sf.pop_back();
        sum-=all[i];
    }
    return;
}
int main(){
    vector<int>nums={2,4,6,8,10};
    vector<int>temp;
    int sum=0;
    cs(0,nums,temp,sum);
    display(final_ans);
}