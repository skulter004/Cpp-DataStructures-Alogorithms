#include<bits/stdc++.h>
using namespace std;

vector<int> firstNegative(vector<int> input, int n, int k){
    deque<int> dq;
    vector<int> ans;

    for(int i = 0; i < k; i++){
        if(input[i] < 0){
            dq.push_back(i);
        }
    }
    
    //store ans of first k size window 
    if(dq.size() > 0){
        ans.push_back( input[dq.front()] );
    }
    else{
        ans.push_back(0);
    }

    //process for remaining windows
    for(int i = k; i < n; i++){
        //removal
        if(!dq.empty() && i - dq.front() >= k ){
            dq.pop_front();
        }
        //addition
        if(input[i] < 0){
            dq.push_back(i);
        }
        //ans store
        if(dq.size() > 0){
            ans.push_back( input[ dq.front() ] );
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
}

//

int main(){
    //vector size
    int size = 5;
    vector<int> input = {-8, 2, 3, -6, 10};
    //window size
    int k = 2;
    vector<int> ans = firstNegative(input, size, k);
    for(int i = 0; i < size-1; i++){
        cout << ans[i] << " " ;
    }
}