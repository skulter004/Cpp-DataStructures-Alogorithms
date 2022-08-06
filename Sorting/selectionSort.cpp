#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void selecsort(int arr[],int n){

    for(int i = 0; i < n; i++){
        int minIndex = i;

        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minIndex]) minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
    for(int  i = 0; i < n; i++){
        cout << arr[i] << " ";
    }cout << endl;
}


int main () {
    int n;
    cin>>n;
    int *arr = new int[n];
    cout << "Enter array element" << endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }

    selecsort(arr,n);

    return 0;
}
