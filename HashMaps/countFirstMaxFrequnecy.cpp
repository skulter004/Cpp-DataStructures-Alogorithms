//try on yourself easy question
//condition : if more than 1 element occur for maximum freq return the element \
which comes first in the array
#include<bits/stdc++.h>
using namespace std;

int maximumFreq(vector<int> arr, int n){
    
    unordered_map<int, int> count;
    
    for(int i = 0; i < n; i++){
        count[arr[i]]++;
    }

    int maxFreq = 0;
    int maxAns = 0;

    for(int i = 0; i < arr.size(); i++){
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    for(int i = 0; i < arr.size(); i++){
        if(maxFreq == count[arr[i]]){
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;
}

int main(){
    vector<int> arr = {5,2,3,5,2};
    cout << maximumFreq(arr, 5) <<endl;
}