#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int getmax(int arr[],int n,int max){
    
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

int getmin(int arr[],int n,int min){
    
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    return min;
}


int main(){
   
   
  int arr[6];
  for(int i=0;i<6;i++) {
      cin>>arr[i];
  }
  int min=INT_MAX;
  int max=INT_MIN;
    cout<<"max="<<getmax(arr,6,INT_MIN)<<endl;

    cout<<"min="<<getmin(arr,6,INT_MAX)<<endl;
    return 0;
}
