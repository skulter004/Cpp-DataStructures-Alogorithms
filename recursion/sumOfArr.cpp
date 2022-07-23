#include <iostream>
using namespace std;

//sum of array using recursion
int arrsum(int *arr ,int size){
    if(size == 0)
    return 0;

    return arr[0] +  arrsum( arr + 1 , size-1 );
}

int main(){
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);
    cout << arrsum( arr , size )<<endl;

}