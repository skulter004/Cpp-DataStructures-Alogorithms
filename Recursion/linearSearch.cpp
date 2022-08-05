#include <iostream>
using namespace std;

// linear search using recursion
bool linesearch(int *arr , int size , int target){
    if(size == 0)
    return false;
    
    if(arr[0]==target)
    return true;

    return linesearch( arr +1 , size -1 , target);
    
}

int main(){
    
    int arr[] = {1,2,3,4,5 ,1,2,3,1,1};
    int size = sizeof(arr)/sizeof(int);
    cout << "using linear searching " << linesearch(arr , size , 1) <<endl;
}