#include<bits/stdc++.h>
#include<vector>
using namespace std;


void sum2(vector<int>v1,int n1,vector<int>v2,int n2){
     int i=n1-1;
     int j=n2-1;
     int carry=0;
     vector<int>ans;
     while (i>=0&&j>=0)
     {
        int val1=v1[i];
        int val2=v2[j];
        int sum=val1+val2+carry;
        carry=sum/10;
        sum =sum%10;
        ans.push_back(sum);
        i--;
        j--;
     }
     while (i>=0)
     {
        int val1=v1[i];
        
        int sum=val1+carry;
        carry=sum/10;
        sum =sum%10;
        
        ans.push_back(sum);
        i--;
        
     }
     while (j>=0)
     {
        
        int val2=v2[j];
        int sum=val2+carry;
        
        carry=sum/10;
        carry=sum/10;
        ans.push_back(sum);
        
        j--;
     }
     while (carry!=0)
     {
        
        int sum=carry;
        
        carry=sum/10;
        sum =sum%10;
        ans.push_back(sum);
        
     }
     
     for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i];
     }
     
 }

int main(){
      vector<int>v1;
      vector<int>v2;
      int n1;
      cin>>n1;
      for(int i=0;i<n1;i++){
          int a;
          cin>>a;
          v1.push_back(a);
      }

       int n2;
      cin>>n2;
      for(int i=0;i<n2;i++){
          int a;
          cin>>a;
          v2.push_back(a);
      }

      sum2(v1,n1,v2,n2);

      return 0;
  }
