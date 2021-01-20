class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int count=0;
    string dp[s.length()][s.length()];
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(i==j){
                    dp[i][j]=s[i];
                }
                else{
                    dp[i][j]=dp[i][j-1]+s[j];
                }
            }
        }
        // arrays that store previous and next occurences of given ith char in string
        unordered_map<char,int>ump;
        vector<int>prev(s.length(),0),next(s.length(),0);
        int PREV=-1;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ump[ch]){
                prev[i]=ump[ch];
                ump[ch]=i;
            }
            else{
                prev[i]=PREV;
                ump[ch]=i;
            }
        }
        int size=s.length();
        unordered_map<char,int>ump2;
        int boolean[1000][1000]={{0}};
        int NEXT=s.length();
        for(int i=s.length()-1;i>=0;i--){
            char ch=s[i];
            if(ump2[ch]){
                next[i]=ump2[ch];
                ump2[ch]=i;
            }
            else{
                next[i]=PREV;
                ump2[ch]=i;
            }
        }
        for(int gap=0;gap<s.length();gap++){
            for(int i=0;i<s.length()-i;i++){
                if(gap==0){
                    boolean[i][gap+i]=1;
                }
                else{
                    int diagMid=boolean[i+1][i+gap-1];
                    int leftCell=boolean[i][i+gap-1];
                    int bottomCell=boolean[i+1][i+gap];
                    string temp=dp[i][gap+i];
                    int eindx=temp.length()-1;
                    if(temp[0]!=temp[eindx]){
                        boolean[i][gap+i]=leftCell+bottomCell-diagMid;
                    }
                    else if(temp[0]==temp[eindx]){
                        if(next[i]>i && prev[gap+i]<gap+i){
                            int farDiagMid=boolean[next[i]+1][prev[gap+i]-1];
                            boolean[i][gap+i]=(2*diagMid)+farDiagMid;
                        }
                        else if(next[i]==prev[gap+i]){
                            boolean[i][gap+i]=(2*diagMid)+1;
                        }
                        else{
                            boolean[i][gap+i]=(2*diagMid)+2;
                        }
                    }
                }
            }
        }
        for(int i=0;i<s.length();i++){
            for(int j=0;j<s.length();j++){
                cout<<boolean[i][j]<<" ";
            }
            cout<<"\n";
        }
        return count;
    }
};