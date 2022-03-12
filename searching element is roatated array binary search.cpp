#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int PIVOT(int arr[],int n )
{
    int start=0;
    int end=n-1;
    int mid=(start+end)/2;
      while (start<end)  {

        if(arr[mid]>=arr[0])
        {
            
            start=mid+1;
            }           
             else{
                end=mid;
            }
            mid=(start+end)/2;
        
    }
      return start;
}

void binarysearch(int arr[],int n,int key,int s,int e){
    
    
    int found=0;
    
    while(s<=e){
        int mid=(s+e)/2;

        if(arr[mid]==key){
        found=1;
        cout<<mid<<" found"<<endl;
        break;
        }
        else if(mid>key){
            e=mid-1;
        }
        else{
            s = mid+1;
        }
        
    }
    if(found==0)
    {
        cout<<"element not present";
    }
}


int main(){
   int arr[5]={7,9,1,2,3,};
   int pivot=PIVOT(arr,5);
   int key; cin>>key;
   
   if(arr[pivot]==key){
       cout<<pivot;
   }
   else if(arr[pivot]>key){
       binarysearch(arr,5,key,0,pivot);

   }
   else{
       binarysearch(arr,5,key,0,pivot-1);
   }
    return 0;
    
}
