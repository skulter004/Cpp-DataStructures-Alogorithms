#include <iostream>
using namespace std;

//bubble sort using recursion
void bubbleSort(int *arr , int size ){
    
    if(size == 0 || size == 1){
        return ;
    }
    
    for(int i=0 ; i<size -1; i++){
    if(arr[i] > arr[i+1]){
        swap(arr[i] , arr[i+1]);
    } 
    
    }
        return bubbleSort(arr  , size-1 );
   
}

int main(){
    //bubble sort
    int arr[] = {5,4,3,2,1};
    int size = sizeof(arr)/sizeof(int);
    bubbleSort(arr , size );

    for(int i=0 ; i<size ; i++ ){
        cout << arr[i] << " ";
    }
}