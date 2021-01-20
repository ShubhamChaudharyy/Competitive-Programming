#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="abaaa";
    string dp[s.length()][s.length()];
    int i=0,j=0;
    for(i=0;i<s.length();i++){
        int diff=i;
        for(j=i;j<s.length();j++){
            if(i==j){
                dp[i][j]=s[j];
            }
            else{
                dp[i][j]=dp[i][j-1]+s[j];
            }
        }
    }
    int boolean[s.length()][s.length()]={{0}};
    int boolean2[s.length()][s.length()]={{0}};
    for(j=0;j<s.length();j++){
        for(i=0;i<s.length()-j;i++){
            if(j==0){
                boolean[i][j+i]=1;
            }
            else{
                string temp=dp[i][j+i];
                int endI=temp.length()-1;
                if(temp[0]==temp[endI] && temp.size()>2){
                    if(boolean[i+1][j+i-1]!=0)
                    boolean[i][j+i]=boolean[i+1][j+i-1]+2;
                    else
                    boolean[i][j+i]=0;
                }
                else if(temp[0]==temp[endI] && temp.size()==2){
                    boolean[i][j+i]=2;
                }
                else{
                    boolean[i][j+i]=0;
                }
            }
        }
    }
    // for subsequence palindrome .... Matrix generation
    // for(j=0;j<s.length();j++){
    //     for(i=0;i<s.length()-j;i++){
    //         if(j==0){
    //             boolean2[i][j+i]=1;
    //         }
    //         else{
    //             string temp=dp[i][j+i];
    //             int endI=temp.length()-1;
    //             if(temp[0]==temp[endI]){
    //                 boolean2[i][j+i]=boolean2[i][j+i-1]+boolean2[i+1][j+i]+1;
    //             }
    //             else{
    //                 boolean2[i][j+i]=boolean2[i][j+i-1]+boolean2[i+1][j+i]-boolean2[i+1][j+i-1];
    //             }
    //         }
    //     }
    // }
    for(i=0;i<s.length();i++){
        for(j=0;j<s.length();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    for(i=0;i<s.length();i++){
        for(j=0;j<s.length();j++){
            cout<<boolean[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    for(i=0;i<s.length();i++){
        for(j=0;j<s.length();j++){
            cout<<boolean2[i][j]<<" ";
        }
        cout<<"\n";
    }
}