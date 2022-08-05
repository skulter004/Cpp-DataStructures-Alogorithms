#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int FIRST(int arr[],int n,int key){
      int first=0;
      int last=n-1;
      bool found=0;int ans=0;
      while(first<=last){
           int mid=(first+last)/2;
           if(arr[mid]==key){
              ans=mid;
              last = mid-1;
           
           }
           else if(arr[mid]<key){
               first=mid+1;
              
           }
           else{
               last=mid-1 ;
           }
      }
      return ans;    
}
int LAST(int arr[],int n,int key){
      int first=0;
      int last=n-1;
      bool found=0;int ans=0;
      while(first<=last){ 
           int mid=(first+last)/2;
           if(arr[mid]==key){
              ans=mid;
              first = mid+1;
           
           }
           else if(arr[mid]<key){
               first=mid+1;
              
           }
           else{
               last=mid-1;  ;
           }
      }
      return ans;    
}




int main(){
    int key;
    cin>>key;

   int arr[]={1,3,5,6,7,7,7,7,8,9,11,23,34};
    cout<<FIRST(arr,10,key)<<" frist ocurence"<<endl;
    cout<<LAST(arr,10,key)<<" last occurence"<<endl;

    return 0;
    
}
