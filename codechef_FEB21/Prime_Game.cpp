#include <bits/stdc++.h>
using namespace std;
long long no_of_primes[2000001]={0};
void SOE(long long n)
{   int dp_count=0;

    bool pri[n + 1];  

    memset(pri, true, sizeof(pri));
 
    for (int iter_p = 2; iter_p * iter_p <= n; iter_p++)
    {   if (pri[iter_p] == true) 
        {
            for (int i = iter_p * iter_p; i <= n; i += iter_p)
                pri[i] = false;
        }
    }
    for (int iter_p = 2; iter_p <= n; iter_p++){
        if (pri[iter_p]) 
            dp_count++;
        no_of_primes[iter_p]=dp_count;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long SIZE,test_Cases;
    cin>>test_Cases;
    SOE(1000000);
    while(test_Cases--){
        long long X,Y;
        cin>>X>>Y;
        if((X==1 || X==2) && Y==1)
        cout<<"Chef \n";
        else if(no_of_primes[X]<=Y)
        cout<<"Chef \n";
        else{
            cout<<"Divyam \n";
        }
    }
	return 0;
}
