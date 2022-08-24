#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge2arrays(int n1, int n2,int arr1[],int arr2[],vector<int> ans){
    
     int i=0,j=0;

     while(i<n1 && j<n2){

         if(arr1[i]<arr2[j]){
             v3.push_back(v1[i]);
             i++;
             
         }
         else{
             v3.push_back(v2[j]);
             
             j++;
         }
        
     }
       while(i<v1.size()){
         v3.push_back(v1[i]);
         i++;
     }
     while(j<v2.size()){
         v3.push_back(v2[j]);
         j++;
     }

     for(int i=0;i<v3.size();i++){
         cout<<v3[i]<<" ";
     }
   
     
     return;
}

void bublsort(int arr[],int n){


   

    for(int  i = 0; i < n ; i++){
        for(int  j = 0; j < n-1; j++){

            if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);

        }
    }

     for(int i=0; i<n; i++){

        cout<<arr[i]<<" ";
    
    }

}

int mid(int n1, int n2, int arr1[], int arr2[]){
    bublsort(arr1, n1);
    bublsort(arr2, n2);
}

int main(){

    int arr[] = {9,8,3,-7,3,9};

    cout << mid(12, 2) << endl;
}
