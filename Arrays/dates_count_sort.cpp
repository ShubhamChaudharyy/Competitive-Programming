#include<bits/stdc++.h>
using namespace std;
    vector<vector<int>>arr={
        {1,4,5},{2,4,3},{0,4,6},{9,5,3},{0,9,9},{1,3,4}
    };
    vector<vector<int>>helper={
        {1,4,5},{2,4,3},{0,4,6},{9,5,3},{0,9,9},{1,3,4}
    };
void solve(){
    vector<int>divi={10,10,10};
    for(int i=2;i>=0;i--){
        vector<int>index(10,0);
        int toDiv=divi[i];
        for(int j=0;j<=5;j++){
            int check=arr[j][i];
            index[check%10]+=1;
        }
        int preSum=0;
        for(int iter=0;iter<index.size();iter++){
            preSum+=index[iter];
            index[iter]=preSum;
        }
        for(int j=0;j<index.size();j++)
            index[j]-=1;
        for(int j=5;j>=0;j--){
            int toCheck=helper[j][i];
            for(int k=0;k<3;k++){
                arr[index[toCheck/toDiv]][k]=helper[j][k];
            }
            index[toCheck/toDiv]--;
        } 
        helper=arr;
        cout<<"\n";
    }
}
int main(){
    solve();
    for(auto x:arr){
        for(int indiv:x)
        cout<<indiv<<" ";
        cout<<endl;
    }
    return 0;
}