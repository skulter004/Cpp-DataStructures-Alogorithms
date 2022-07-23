#include <iostream>
using namespace std;

//partition program for quick sort
int partition(int *arr , int start , int end){
    int pivot = arr[start];
    int count =0;
    for (int i=start+1 ; i<=end; i ++){
        if(arr[i] < pivot){
            count++;
        }
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex] , arr[start]);

    //left right part consideration
    int i= start,j=end;
    while(i < pivotIndex && j > pivotIndex){

        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++] , arr[j--]);
        }
    }
    return pivotIndex;
}
//quick sort using reccursion
void quickSort(int* arr , int start , int end){
    if(start >= end){
        return;
    }
    //partition
    int p = partition(arr ,start , end);
    
    //left part
    quickSort(arr , start , p -1);

    //right part
    quickSort(arr , p +1 , end);
}

int main(){
    int arr[] = {2,3,5,-1,0,5,-2,5,7,8,5,4,3,2,56,8,9,4,3,6,45,334,5,54,3,23,45,5,6,7,8,34,32,6,7,45,6,8,463,67};
      int size = sizeof(arr)/sizeof(int);
      quickSort(arr , 0 , size-1 );

        for(int i=0 ; i<size ; i++ ){
           cout << arr[i] << " ";
        }
}