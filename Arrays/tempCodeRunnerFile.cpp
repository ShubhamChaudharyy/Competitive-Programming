#include<bits/stdc++.h>
using namespace std;
int findUnsortedSubarray(vector<int>& arr){
        int low=0,end=arr.size()-1;
        while(low<=end-1){
            if(arr[low]<=arr[low+1])
            low++;
            else
            break;
        }
        while(end>=1){
            if(arr[end]>=arr[end-1])
            end--;
            else
            break;
        }
        if(end==0 && low==arr.size()-1)
            return 0;
        int ans=end-low-1;
        cout<<low<<" "<<end<<"\n";
        int ele=0;
        for(int i=0;i<=low;i++){
            int l=low+1;
            int h=arr.size()-1;
            for(int j=l;j<=h;j++){
                if(arr[j]<arr[i]){
                    ele+=1;
                }
            }
            cout<<ele<<"\n";
        }
        ans+=ele;
        ele=0;
        for(int i=end;i<arr.size();i++){
            int l=0;
            int h=end-1;
            for(int j=l;j<=h;j++){
                if(arr[j]>arr[i]){
                    ele+=1;
                }
            }
            cout<<ele<<"\n";
        }
        return ans+ele;
}
int main(){
    vector<int>k={1,3,5,4,2};
    int ans=findUnsortedSubarray(k);
    cout<<ans<<"\n";
}