#include <bits/stdc++.h>
using namespace std;
long long maxf(long long first,long long mid,long long end){
    return abs(first-mid)+abs(mid-end)+abs(end-first);
}
int main() {
    long long size,TestCases;
    cin>>TestCases;
    while(TestCases--){
        long long size;
        long long MAXIMUM=INT_MIN,MINIMUM=INT_MAX;
        cin>>size;
        vector<long long>vec;
        for(long long iter=0;iter<size;iter++){
            long long indiv;
            cin>>indiv;
            vec.push_back(indiv);
            MINIMUM=min(indiv,MINIMUM);
            MAXIMUM=max(indiv,MAXIMUM);
        }
        if(MAXIMUM==MINIMUM)
        {    
            cout<<0<<"\n";
            continue;
        }
        long long output=0;
        for(int iter=0;iter<size;iter++)
            output=max(output,maxf(MINIMUM,vec[iter],MAXIMUM));
        cout<<output<<"\n";
    }
	return 0;
}
