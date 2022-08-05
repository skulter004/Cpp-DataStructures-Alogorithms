#include<bits/stdc++.h>
using namespace std;

//given a array contains diffrent size of the rope price of the rope is equal to their sum \
take 2 min elelemt from array and add them into hea and store it in a ans 

int minCost(int arr[], int n){
    //min heap
    priority_queue<int, vector<int>, greater<int> > pq; 

    for(int i = 0; i < n; i++){
        pq.push(arr[i]);
    }

    int cost = 0;
    while(pq.size() > 1){
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        int sum = a + b;
        cost += sum;
        pq.push(sum);
    }
    return cost;
}

int main(){
    int arr[] = {4, 3, 2, 6};
    int n = 4;
    cout << "The cost is " << minCost(arr,n);
}