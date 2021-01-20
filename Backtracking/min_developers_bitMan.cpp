class Solution {
public:
    void solve(vector<int>choice,vector<int>inp,int Mini,vector<int>&MinVec,int check,unordered_map<int,int>helper){
        if(inp.size()==0){
            int fact=0;
            if(choice.size()==0){
                return;
            }
            for(int i=0;i<choice.size();i++){
                fact=fact|choice[i];
            }
            int count=0;
            while(fact!=0){
                int rbsm=fact&-fact;
                fact=fact-rbsm;
                count++;
            }
            if(count==check){
                if(choice.size()<Mini){
                    Mini=choice.size();
                    cout<<Mini<<"\n";
                    MinVec.clear();
                    for(int i=0;i<choice.size();i++){
                        int index=helper[choice[i]];
                        MinVec.push_back(index);
                    }
                }
            }
            return;
        }
        vector<int>a1=choice;
        vector<int>a2=choice;
        a2.push_back(inp[0]);
        inp.erase(inp.begin());
        solve(a1,inp,Mini,MinVec,check,helper);
        solve(a2,inp,Mini,MinVec,check,helper);
    }
    vector<int> smallestSufficientTeam(vector<string>& skill, vector<vector<string>>& people) {
        unordered_map<string,int>ump;
        vector<int>bin;
        for(int i=0;i<skill.size();i++){
            string temp=skill[i];
            ump[temp]=i;
            bin.push_back(0);
        }
        vector<int>arr;
        unordered_map<int,int>arrMap;
        for(int i=0;i<people.size();i++){
            vector<int>helper=bin;
            vector<string>temp=people[i];
            int highP=helper.size();
            int dec;
            int sum2dec=0;
            for(int m=0;m<temp.size();m++){
                string unq=temp[m];
                int index=ump[unq];
                helper[index]=1;
                dec=pow(2,highP-index-1);
                sum2dec+=dec;
            }
            arr.push_back(sum2dec);
            arrMap[sum2dec]=i;
        }
        ump.clear();
        bin.clear();
        vector<int>temp;
        int fix=skill.size();
        int Min=INT_MAX;
        vector<int>MinVec;
        solve(temp,arr,Min,MinVec,fix,arrMap); 
    }
};