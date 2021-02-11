#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b){
    a=a+b;b=a-b;a=a-b;
}
int partition(vector<int>&arr,int start,int end){
    int pivot=arr[start];
    int i=start,j=end;
    while(i<j){
        if(arr[i]<=pivot) 
            i++;
        else if(arr[j]>pivot) 
            j--;
        else if(arr[j]<=pivot && arr[i]>pivot) 
            swap(arr[j],arr[i]);
    }
    if(start!=j-1)
    swap(arr[start],arr[j-1]);
    return j-1;
}
void display(vector<int>num){
    for(int c:num)
    cout<<c<<" ";
    cout<<"\n";
}
void quickSort(vector<int>&nums,int start,int end){
    if(start<end){
        int pivot=partition(nums,start,end);
        quickSort(nums,start,pivot);
        quickSort(nums,pivot+1,end);
    }
}
int main(){
    vector<int>num={1,18,2,1,16,7,18,9,23};
    quickSort(num,0,8);
    display(num);
    return 0;
}