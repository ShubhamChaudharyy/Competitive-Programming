#include <bits/stdc++.h>
using namespace std;
int main() {
    long long T;
    cin>>T;
    while(T--){
        long long Size;
        cin>>Size;
        vector<long long  >wght(Size,0),Li(Size,0),Ci(Size,0),Ji(Size,0);
        for(long long iter=0;iter<Size;iter++){
            long long num;cin>>num;wght[num-1]=num;Ci[num-1]=iter;
            Ji[iter]=num;
        }
        for(long long iter=0;iter<Size;iter++){
            long long pj;cin>>pj;Li[Ji[iter]-1]=pj;
        }
        long long output=0;
        for(int iter=1;iter<Size;iter++){
            if(Ci[iter]<=Ci[iter-1]){
                long long diff=Ci[iter-1]-Ci[iter];
                long long noj=(diff/Li[iter])+1;
                output+=noj;
                Ci[iter]+=(noj*Li[iter]);
            }
        }
        cout<<output<<"\n";
    }
	return 0;
}
