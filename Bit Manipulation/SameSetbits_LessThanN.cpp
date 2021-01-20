#include<bits/stdc++.h>
using namespace std;
int facto(int n){
    int fact=1;
    int i=1;
    while(i<=n){
        fact=fact*i;
        i++;
    }
    return fact;
}
int nCr(int n,int r){
    int numr=facto(n);
    int deno=facto(n-r)*facto(r);
    return (numr/deno);
}
int solve(int num,int msk,int sb,int plc,int &output){
    if(msk==0 || plc==1){
        return 0;
    }
    if((msk&num)!=0){
        msk=msk>>1;
        plc-=1;
        output=solve(num,msk,sb-1,plc,output)+nCr(plc,sb);
        return output;
    }
    else{
        plc-=1;
        msk=msk>>1;
        solve(num,msk,sb,plc,output);
    }
}
int main(){
    int N;
    cin>>N;
    int temp=N;
    int sb=0,places;
    while(temp!=0){
        int mask=(temp&-temp);
        if((mask&temp)!=0)
        sb++;
        temp=temp-mask;
    }
    int iter=1;
    while((1<<(iter+1))<=N){
        iter++;
    }
    int MASK=1<<iter;
    places=iter+1;
    int ans=0;
    int a=solve(N,MASK,sb,places,ans);
    cout<<a<<endl;
    return 0;
}