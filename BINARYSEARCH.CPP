#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

void binarysearch(int arr[],int n,int key){
    int start=0;
    int end=n-1;
    int found=0;
    
    while(start<=end){
        int mid=(start+end)/2;

        if(arr[mid]==key){
        found=1;
        cout<<mid<<" found"<<endl;
        break;
        }
        else if(mid>key){
            end=mid-1;
        }
        else{
            start = mid+1;
        }
        
    }
    if(found==0)
    {
        cout<<"element not present";
    }
}




int main(){
    int key;
    cin>>key;

   int arr[]={1,3,5,6,7,8,9,11,23,34};
    binarysearch(arr,10,key);
    return 0;
    
}
