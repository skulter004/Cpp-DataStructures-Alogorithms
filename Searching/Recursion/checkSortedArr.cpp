#include <iostream>
using namespace std;

// check sorted array with recusrion
bool issorted(int *arr , int size){
    if(size==0||size==1)
    return 1;
    if(arr[0]>arr[1])
    return 0;

    return issorted(arr +1 , size -1 );
    
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    
    int size = sizeof(arr) / sizeof(int);

    if(issorted( arr , size) )
        cout << "sorted" << endl;
    else
        cout << "not sorted" << endl;
}