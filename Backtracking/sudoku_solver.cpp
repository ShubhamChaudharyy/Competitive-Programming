#include<bits/stdc++.h>
using namespace std;
void recursion(int arr[][],int i,int j){
    if(j==arr[0].length()-1){

    }
    else {

    }
    if(arr[i][j]!=0){
        recursion(arr,i,j);
    }
    else {
        for(int pos=1;pos<=9;pos++){
            if(isValid(arr,i,j,pos)){
                arr[i][j]=pos;
                recursion(arr,i,j);
                arr [i][j]=0;
            }
        }
    }
}
int main(){
    recursion()
}