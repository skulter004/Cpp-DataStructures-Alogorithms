#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void selecsort(int arr[],int n){

    for(int i=0;i<n;i++){
     int minindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        swap(arr[minindex],arr[i]);
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
selecsort(arr,n);

return 0;
}
