//this is a running stream and unsortted manner\
so 1st  approach is that use insertion sort and return the median fo the array\
tc is O[n^2]

//signum function take two nums and return 0 is they sre equal if 1 if a is greater than b -1 ig a less than b
//2nd approach\
using max and min heap tc is O[nlogn]

#include<bits/stdc++.h>
using namespace std;

int signum(int a, int b){
    if(a == b) return 0;

    else if(a > b) return 1;

    else return -1;
}

void callMedian(int element, vector<int> &arr,priority_queue<int> &maxi,priority_queue<int, vector<int>, greater<int> > &mini, int &median ){
    
    switch(signum(maxi.size(), mini.size())){
        case 0: if(element > median){
                    mini.push(element);
                    median = mini.top();
                }
                else{
                    maxi.push(element);
                    median = maxi.top();
                }
                break;
        case 1: if(element > median){
                    mini.push(element);
                    median = (mini.top() + maxi.top())/2;
                }
                else{
                    mini.push(maxi.top());
                    maxi.pop();
                    maxi.push(element);
                    median = (mini.top() + maxi.top())/2;
                }
                break;
        case -1: if(element > median){
                    maxi.push(mini.top());
                    mini.pop();
                    mini.push(element);
                    median = (mini.top() + maxi.top())/2;
                }
                else{
                    maxi.push(element);
                    median = (mini.top() + maxi.top())/2;
                }
                break;

    }
}

vector<int> findMedian(vector<int> &arr, int n){
    
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int median  = 0;

    for(int  i = 0; i < n; i++){
        callMedian(arr[i], arr, maxHeap, minHeap, median);
        ans.push_back(median);
    }
    return ans;
}

int main(){
    vector<int> input = {3, 2, 4, 9, 7, 7, 1, 10, 5, 8};
    vector<int> ans = findMedian(input, 10);
    
    cout << "Median is " << ans[ans.size()-1] << endl;
    
}