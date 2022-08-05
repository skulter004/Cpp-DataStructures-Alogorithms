#include <iostream>
using namespace std;

//insertion sort usign recursion
void insertionSort(int* arr , int itr , int size){
    if(size == 0 || size == 1 || itr == size ){
        return;
    }
    int temp = arr[itr];
    for(int i=itr-1 ; i >=0 ; i--){
        if(arr[i] > arr[itr]){
            arr[i+1] = arr[i];
        }
        else{
            break;
        }
    }
    arr[itr] == temp;
    
    return insertionSort(arr, itr +1 , size);

}

int main(){
     int arr[] = {5,4,3,2,1 , 56, 3, 2 ,0};
      int size = sizeof(arr)/sizeof(int);
      insertionSort(arr , 0 , size );

        for(int i=0 ; i<size ; i++ ){
           cout << arr[i] << " ";
        }
}