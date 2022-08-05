#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i){
    //1based indexing
    int largest = i;
    int left = 2*i;
    int right = 2*i +1;
    if(left <= n && arr[largest] < arr[left]) 
        largest = left;

    if(right <= n && arr[largest] < arr[right])
        largest  = right;

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeap(vector<int> a, vector<int> b, int n, int m){
    //step1 merge both arrys into 1
    vector<int> ans;
    ans.push_back(-1);
    for(auto i:a)
        ans.push_back(i);
    for(auto i:b)
        ans.push_back(i);
    //step2 build heap using merged array
    int size = ans.size();
    for(int i = size/2; i > 0; i--){
        heapify(ans, size, i);
    }
    return ans;
}

int main(){
    string str;
    int n = 4 , m = 3;
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};
    vector<int> ans  = mergeHeap(a, b, n, m);
    for(int i = 1; i < ans.size(); i++){
        cout << ans[i] << " ";
    }cout << endl;
}