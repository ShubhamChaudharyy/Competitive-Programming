#include<bits/stdc++.h>
#define ll long long
using namespace std;
vois solve(ll tc){
    while(tc--){
        ll N;
        cin>>N;
        vector<string>a;
        string check="2020";
        string main;
        cin>>main;
        ll start=0,end=N-1;
        ll i=0,j=3;
        string s1=" ",s2=" ";
        s1 += main[0]+main[1]+main[2]+main[3];
        s2 += main[N-1]+main[N-2]+main[N-3]+main[N-4];
        ll notFound=0;
        while(!notFound){
            if(main[start]==check[i]){
                i++;
                start++;
            }
            else
            {
                notFound==1;
            }
            if(i==4)
            break;
        }
        notFound=0;
        while(!notFound){
            if(main[end]==check[j]){
                j--;
                end--;
            }
            else{
                notFound=1;
            }
            if(j==-1)
            break;
        }
        if(s2==check || s1==check || i>=j){
            cout<<"YES \n";
        }
        else 
        cout<<"NO \n";
    }
}
void input(){
    ll T;
    solve(T);
}
int main(){
    input();
    return 0;
}