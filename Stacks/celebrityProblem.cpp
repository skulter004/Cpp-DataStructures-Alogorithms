#include<bits/stdc++.h>
using namespace std;
//NxN matrix is given find the celerbity is there or not, 2 conditions are every one knows celebrtity \
celebrity knows no one
bool knows(vector<vector<int>> m, int a, int b){
    if(m[a][b] == 1)
    return true;

    else
    return false;
}
int celebrity(vector<vector<int>> m, int n){
    stack<int> s;

    //push all element in stack
    for(int i = 0; i < n; i++){
        s.push(i);
    }
    while(s.size() > 1){
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if(knows(m,a,b)){
            s.push(b);
        }
        else
        s.push(a);
    }
    int candidate = s.top();
    //single element in stack can be potential celebrity
    int zeroCount = 0;
    for(int  i = 0; i < n; i++){
        if(m[candidate][i] == 0)
        zeroCount++;
    }
    if(zeroCount != n){
        return -1;
    }

    int oneCount = 0;
    for(int  i = 0; i < n; i++){
        if(m[i][candidate] == 1)
        oneCount++;
    }
    if(oneCount != n-1){
        return -1;
    }

    return candidate;
}
int main(){
    vector<vector<int>> input = {{0, 0, 1}, {0, 0, 1}, {0, 0, 0}};
    cout << celebrity(input, 3) << endl;
}