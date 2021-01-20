#include<bits/stdc++.h>
using namespace std;
void solve(int tc){
    while(tc--){
        string s1,s2;
        cin>>s1>>s2;
        vector<string>prefix1,prefix2;
        string temp="";
        for(int i=0;i<s1.length();i++){
            temp+=s1[i];
            prefix1.push_back(temp);
        }
        temp="";
        for(int j=0;j<s2.length();j++){
            temp+=s2[j];
            prefix2.push_back(temp);
        }
        string LCS[prefix1.size()][prefix2.size()];
        for(int i=0;i<prefix1.size();i++){
            string str1=prefix1[i];
            int endI1=str1.size()-1;
            for(int j=0;j<prefix2.size();j++){
                string str2=prefix2[j];
                int endI2=str2.size()-1;
                if(str2[endI2]==str1[endI1]){
                    if(i!=0 && j!=0){
                        LCS[i][j]=LCS[i-1][j-1]+str1[endI2];
                    }
                    else{
                        LCS[i][j]=str2[endI2];
                    }
                }
                else{
                    LCS[i][j]=LCS[i-1][j-1];
                }
            }
        }
        for(int i=0;i<prefix1.size();i++){
            for(int j=0;j<prefix2.size();j++){
                cout<<LCS[i][j]<<" ";
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