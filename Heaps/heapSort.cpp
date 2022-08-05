#include<iostream>
#include<bits/stdc++.h>
#include<queue>

using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i +1;
    //we have taken 1 based idexing so will check for <= n
    if(left <= n && arr[largest] < arr[left]) 
    largest = left;

    if(right <= n && arr[largest] < arr[right])
    largest  = right;

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    int size = n;
    while(size > 1){
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);

    }
}


int main(){
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    //building the heap for 1 base indexing we go from n/2 and for 0 base from n/2 -1
    for(int i = n/2; i > 0; i--){
        heapify(arr, n, i);
    }
    cout << "printing array now" << endl;
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }cout << endl;

    heapSort(arr, n);
    cout << "printing array now" << endl;
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }cout << endl;

    cout <<"Using priority queue" << endl;
    priority_queue<int> pq; // this is a max heap;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    cout << pq.top() << endl;

    priority_queue<int, vector<int>, greater<int> > minHeap; //this is a min heap


}