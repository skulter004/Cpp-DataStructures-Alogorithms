#include <iostream>
using namespace std;

//function  for merging the sorted arrays
void merge(int *arr, int start ,int end){
    int mid = (start+end)/2;

    int l1 = mid - start +1;
    int l2 = end - mid ;

    int *first = new int[l1];
    int *second = new int[l2];

    int k = start ;
    for(int i=0 ; i<l1 ; i++){
        first[i] = arr[k++];
    }

     k = mid +1 ;
    for(int i=0 ; i<l2 ; i++){
        second[i] = arr[k++];
    }

//merge 2arrays part of merge sort
    int index1= 0;
    int index2= 0;
    int mainarrayindex = start;
    while(index1 < l1 && index2 < l2){
        if(first[index1]  < second[index2]){
            arr[mainarrayindex++] = first[index1] ;
            index1++;
        }
        else{
            arr[mainarrayindex++] = second[index2] ;
            index2++;
        }
    }
    while(index1 < l1){
        arr[mainarrayindex++] = first[index1];
        index1++;
    }
     while(index2 < l2){
        arr[mainarrayindex++] = second[index2];
        index2++;
    }

    delete []first;
    delete []first;
}

//merge sort using recursion //divide array in parts
void mergeSort(int* arr , int start , int end){
    if(start >= end){
        return;
    }
    int mid = (start+end)/2;
    mergeSort(arr , start , mid);
    mergeSort(arr , mid +1 , end);

   merge(arr , start , end);

}

int main(){
    int arr[] = {5,4,3,2,1 , 56, 3, 2 ,0};
      int size = sizeof(arr)/sizeof(int);
      mergeSort(arr , 0 , size-1 );

        for(int i=0 ; i<size ; i++ ){
           cout << arr[i] << " ";
        }
}