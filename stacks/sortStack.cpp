#include<iostream>
#include<stack>
using namespace std;
void sortedInsert(stack<int> &stack, int num){
    if(stack.empty() || (!stack.empty() && stack.top() < num )){
        stack.push(num);
        return;
    }
    int n = stack.top();
    stack.pop();

    //recursive call
    sortedInsert(stack, num);
    stack.push(n);

}
void sortStack(stack<int> &stack)
{
	// Write your code here
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();
    //recursive call
    sortStack(stack);

    sortedInsert(stack, num);
    return;
}

int main(){
    stack<int> stack;
    stack.push(3);
    stack.push(-7);
    stack.push(9);
    stack.push(-2);
    stack.push(5);
    sortStack(stack);

    cout << stack.top() << endl;

}