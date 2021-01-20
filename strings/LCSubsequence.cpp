#include<bits/stdc++.h>
using namespace std;
void solve(int tc){
    while(tc--){
        string s1,s2;
        cin>>s1>>s2;
        int row=s1.length();
        int col=s2.length();
        int arr[row+1][col+1];
        for(int end1=s1.length();end1>=0;end1--){
            for(int end2=s2.length();end2>=0;end2--){
                if(end1==s1.length() || end2==s2.length()){
                    arr[end1][end2]=0;
                }
                else{
                    if(s1[end1]!=s2[end2])
                        arr[end1][end2]=max(arr[end1+1][end2],arr[end1][end2+1]);
                    else if(s1[end1]==s2[end2])
                        arr[end1][end2]=1+arr[end1+1][end2+1];
                }
            }
        }
        for(int i=0;i<=s1.length();i++){
            for(int j=0;j<=s2.length();j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}
void input(){
    int t;
    cin>>t;
    solve(t);
}
int main(){
    input();
    return 0;
}