#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

void twosum(int arr[],int n,int sum){
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
           for(int k=j+1;k<n;k++){
               if(arr[i]+arr[j]+arr[k]==sum){
                   cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
               }
               else{
                   continue;
               }
           }
        }
    }
   
}




int main(){
   int arr[]={1,2,3,4,5};
  twosum(arr,5,6);
    return 0;
    
}
