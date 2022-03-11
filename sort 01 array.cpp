#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

void printarray(int arr[],int n){

    int start=0;
    int end=n-1;
    while(start < end){
      if(arr[start]==1){
          start++;
        }
        else if(arr[end]==0){
            end--;
        }
        swap(arr[start],arr[end]);

    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}




int main(){
   int arr[]={1,0,0,1,0,1,1,1,0,0,0};
  printarray(arr,11);
    return 0;
    
}
