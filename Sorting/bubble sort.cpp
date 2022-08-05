#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void bublsort(int arr[],int n){

for(int j=0;j<n;j++)
{
    for(int i=0;i<n-1;i++){
    if(arr[i]>arr[i+1]){
    swap(arr[i],arr[i+1]);
    }
    else{
        continue;
    }
    
}
}
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
 
    }

}
int main () {
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];

}
bublsort(arr,n);

return 0;
}
