//number of subbrays are N*(N+1)/2
//approach is get the sum of all subarrays into a vector and sort it and get the k value from back
#include<bits/stdc++.h>
using namespace std;

//1st approach O[n^2 logn] sc is O[n^2]
int kLargestSumSubArrayLong(vector<int> arr, int k){
    vector<int> sumStore;
    int n = arr.size();
    for(int  i = 0; i < n; i++){
        int sum = 0;
        for(int  j = i; j < n; j++){
            sum += arr[j];
            sumStore.push_back(sum);//if error move it below
        }
    }
    sort(sumStore.begin(), sumStore.end());

    return sumStore[sumStore.size()-k];
}

//2nd appraoch using min heap

int kLargestSumSubArray(vector<int> arr, int k){
    priority_queue<int, vector<int>, greater<int> > mini;

    int n = arr.size();
    for(int  i = 0; i < n; i++){
        int sum = 0;
        for(int  j = i; j < n; j++){
            sum += arr[j];
            if(mini.size() < k){
                mini.push(sum);
            }
            else{
                if(sum > mini.top()){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top();
}

int main(){
    vector<int> arr = {1,2,3,4};
    int k = 2;
    cout << kLargestSumSubArray(arr, k) << endl;
}