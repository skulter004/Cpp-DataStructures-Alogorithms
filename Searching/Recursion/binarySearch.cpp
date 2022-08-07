#include <iostream>
using namespace std;

// binary search using recursion for Bsearch array must be sorted
bool binarysearch(int *arr ,  int size , int s , int e , int target){
     
     int mid = (s+e)/2;
 
     if(s < e) 
         return 0;

     if(arr[mid] == target)
         return 1;

     if(arr[mid]>target)
         return (arr , size , s , mid -1 , target);
    
         return (arr , size , mid +1 , e , target);

}

int main(){
    
    int arr[] = {1,2,3,4,5 ,1,2,3,1,1};
    int size = sizeof(arr)/sizeof(int);
    cout << "using binary searching " << binarysearch(arr , size , 0 , size , 10 ) <<endl;
}