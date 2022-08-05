#include<bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k){
    //pushing 1st k element to stack
    stack<int> s;
    for(int i = 0; i < k; i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }

    //fetch element from stack to queue
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
    }
    //push back 1st n-k lelemt from the queue
    int n  = q.size() - k;
    for(int i = 0; i < n; i++){
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}

int main(){
    int size = 5;
    queue<int> q;
    int k = 3;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    queue<int> ans = modifyQueue(q, k);
    while(!ans.empty()){
        cout << ans.front() << " ";
        ans.pop();
    }
}