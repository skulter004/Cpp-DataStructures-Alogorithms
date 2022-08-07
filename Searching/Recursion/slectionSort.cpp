#include <iostream>
using namespace std;

//selection sort using recursion
void slecSort(int* arr , int itr , int size){
    if(size == 0 || size == 1 || itr == size ){
        return;
    }
     
     for(int i=itr+1 ; i<size ; i++ ){
         if(arr[itr]>arr[i]){
             swap(arr[itr] , arr[i]);
         }
     }

     return slecSort(arr, itr+1 ,size);

}

int main(){
    int arr[] = {5,4,3,2,1 , 56, 3, 2 ,0};
     int size = sizeof(arr)/sizeof(int);
     slecSort(arr , 0 , size );

       for(int i=0 ; i<size ; i++ ){
           cout << arr[i] << " ";
       }
}