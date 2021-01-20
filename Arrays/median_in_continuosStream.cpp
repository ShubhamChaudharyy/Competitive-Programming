#include<bits/stdc++.h>
#define ll long long
using namespace std;
priority_queue<int,vector<int>,greater<int>>Min;
priority_queue<int,vector<int>>Max;

// 3 11 2 4 5 1 0 19 8
// Max 0 1 2 3 4
// Min 19 11 8 5 
void balanceHeaps(int inc)
{
    if(Max.size()>Min.size()){
        if( inc >= Max.top() ){
            Min.push(inc);
        }
        else if( inc < Max.top()  ){
            Min.push(Max.top());
            Max.pop();
            Max.push(inc);
        }
    }
    else if(Max.size()==Min.size()){
        if(inc <= Min.top()){
            Max.push(inc);
        }
        else if(inc > Min.top()){
            Max.push(Min.top());
            Min.pop();
            Min.push(inc);
        }
    }
}
void insertHeap(int &num)
{
    if(Max.empty()){
        Max.push(num);
    }
    else
    balanceHeaps(num);
}
double getMedian()
{   int size=Min.size()+Max.size();
    double ans;
    if(size%2!=0){
        return Max.top();
    }
    else if(size%2==0){
        ans=double(Max.top()+Min.top())/2;
    }
    return ans;
}
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int val;
        cin>>val;
        insertHeap(val);
        cout<<getMedian()<<"\n";
    }
}
// 1 3 3 5 6 7 7 11 12