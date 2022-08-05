#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
void merge2arrays(vector<int>v1,vector<int>v2,vector<int>v3){
    
     int i=0,j=0;

     while(i<v1.size() && j<v2.size()){

         if(v1[i]<v2[j]){
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
int main(){
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    v1.push_back(67);
    v1.push_back(68);
    v1.push_back(69);
    v1.push_back(70);

    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(6);
    v2.push_back(7);
    merge2arrays(v1,v2,v3);

    return 0;
}
