#include<bits/stdc++.h>
using namespace std;

/// implemetation of kth smalest using heap
int kthSmallest(int arr[], int r, int k){
    priority_queue<int> pq;
    //1st step
    for(int i = 0; i < k; i++){
        pq.push(arr[i]);
    }
    for(int i = k; i < r; i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main(){
    int arr[] = {7, 10, 4, 3, 28, 15};
    int n = 6;
    int k = 5;
    cout << "Kth smallest element is " << kthSmallest(arr, n, k);
}