#include<bits/stdc++.h>
using namespace std;
void display(vector<int>all){
    for(int c:all){
        cout<<c<<" ";
    }
    cout<<"\n";
}
void form(int ssf,int start,vector<int>all){
    if(ssf==0){
        display(all);
        return;
    }
    for(int i=start;i<all.size()-1;i++){
        for(int j=i+1;j<all.size();j++){
            if(all[i]<all[j]){
                int temp=all[i];all[i]=all[j];all[j]=temp;
                form(ssf-1,i+1,all);
                temp=all[i];all[i]=all[j];all[j]=temp;
            }
        }
    }
    display(all);
    return;
}
int main(){
    vector<int>g={1,2,3,4,5,6};
    form(2,0,g);
}