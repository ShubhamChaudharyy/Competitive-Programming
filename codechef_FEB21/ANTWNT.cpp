#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>find_equation(ll cur_node_val,ll ff_node_val,unordered_map<ll,vector<ll>>mptemp,unordered_map<ll,vector<ll>>vertex){
    vector<ll>waiting;
    ll connected_nodes=mptemp[cur_node_val].size();
    if(connected_nodes>0){
        for(ll iter=0;iter<connected_nodes;iter++){
            vector<ll>temp=find_equation(mptemp[cur_node_val][iter],connected_nodes*ff_node_val,mptemp,vertex);
            for(ll c:temp){
                vertex[cur_node_val].push_back(c);
            }
        }
    }
    else{
        waiting.push_back(ff_node_val);return waiting;
    }
    return vertex[cur_node_val];
}
// void display(unordered_map<ll,vector<ll>>eq_map){
//     for(auto x:eq_map){
//         cout<<x.first<<":";
//         for(ll c:x.second){
//             cout<<c<<" ";
//         }
//         cout<<"\n";
//     }
// }
int main(){
    ll num;
    cin>>num;
    ll roots=num-1;
    unordered_map<ll,vector<ll>>ump;
    for(ll iter=2;iter<=num;iter++){
        ll parent_num;
        cin>>parent_num;
        ump[parent_num].push_back(iter);
    }
    unordered_map<ll,vector<ll>>eq_map;
    ll divide=0;
    for(ll iter=1;iter<=num;iter++){
        vector<ll>output=find_equation(iter,1,ump,eq_map);
        eq_map[iter]=output;
    }
    // display(eq_map);
    ll QUERIES;
    cin>>QUERIES;
    while(QUERIES--){
        ll node_val,tasks;
        cin>>node_val>>tasks;
        ll output=0;
        for(ll c:eq_map[node_val]){
            if(tasks%c==0)
                output+=tasks/c;
        }
        cout<<tasks-output<<"\n";
    }
    return 0;
}