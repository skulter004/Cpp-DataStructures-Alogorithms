#include<iostream>
#include<stack>

using namespace std;
void solve(stack<int> &input, int count, int size){
    if(count == size/2){
        input.pop();
        return ;
    }
    int num = input.top();
    input.pop();

    //recursive call
    solve(input, count++, size);
    input.push(num);
}
void deleteMiddle(stack<int> &input , int s){
    int count = 0;
    solve(input, count, s);
    return ;
}
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    deleteMiddle(s, 4);
    
}