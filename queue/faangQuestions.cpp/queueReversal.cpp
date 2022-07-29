#include<bits/stdc++.h>
using namespace std;

//stack approach
queue<int> QueueReverse(queue<int> q){
    stack<int> s;
    while(!q.empty()){
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while(!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }

    return q;
}

//apply reccursion approach

int main(){
    
}