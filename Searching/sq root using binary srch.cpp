#include<iostream>
using namespace std;
int sqroot(int num){
    int n=num/2;
    int s=1;int e=n;
    int mid=0;

    while(s<=e){
        mid = (s+e)/2;
        if(mid * mid==num){
            return mid;
        }
        else if(mid*mid>num){
            e=mid-1;
        }
        else
        {
          s=mid+1;
        }
      
            }
            return mid;
}
int main(){
   int n;
   cin>>n;
   cout<<sqroot(n);
    return 0;
}
