#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>&a,pair<int,int>&b){
    return a.first<b.first;
}
int maxIndexDiff(int arr[], int n) 
{ 
    int start=0,end=n-1,found=0,answer;
    vector<pair<int,int>>a;
    for(int i=0;i<n;i++){
        int item=arr[i];
        a.push_back(make_pair(item,i));
    }
    sort(a.begin(),a.end(),cmp);
    int Max=a[n-1].second;
    int MaxGap=-1;
    for(int i=n-2;i>=0;i--){
        Max=max(Max,a[i].second);
        MaxGap=max(MaxGap,Max-a[i].second);
    }
    return MaxGap;
}

// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        
        //printing 0 if size is 1
        if(num ==1 ){
            cout<<0<<endl;
            continue;
        }
        
        //calling maxIndexDiff() function
        cout<<maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}   // } Driver Code Ends