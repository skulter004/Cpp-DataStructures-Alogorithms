#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int strength(int input1, int input2[], int input3){

    int k = 0;
    int arrSum = 0;

    for(int i = 0; i < input1; i++){
        arrSum += input2[i];
    }
    
    
    
    return k;
}

int main(){
    int n = 3;
    int arr[] = {2, 3, 4};
    int s = 2;
    cout << strength(n, arr, s) << endl;
}
