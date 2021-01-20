#include<bits/stdc++.h>
using namespace std;
void insert(priority_queue<pair<int,int>>&np,int x,int &iter){
    iter--;
    np.push(make_pair(iter,x));
}
void pop(priority_queue<pair<int,int>>pq){
    while(!pq.empty()){
        cout<<pq.top().second<<"\n";
        pq.pop();
    }
}
void input(){
    priority_queue<pair<int,int>>pq;
    int cnt=3;
    insert(pq,1,cnt);
    insert(pq,2,cnt);
    insert(pq,3,cnt);
    pop(pq);
}

int main(){
    input();
    return 0;
}