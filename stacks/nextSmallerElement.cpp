#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//return the next smaller element from the given element in the array
vector<int> NextSmaller(vector<int> &arr, int n){
    
    stack<int> s;
    s.push(-1);
    //creating ans vector
    vector<int> ans(n);

    for(int i = n-1; i>= 0; i--){
        int curr = arr[i];
        while(s.top() >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}
int main(){
    vector<int> arr ={2, 1, 4, 3};
    vector<int> ans = NextSmaller(arr, 4);
}