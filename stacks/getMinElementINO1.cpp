#include<bits/stdc++.h>
using namespace std;

class specialStack{

    stack<int> s;
    int mini;
    public:
    void push(int data){
        //for 1st element
        if(s.empty()){
            s.push(data);
            mini = data;
        }
        else{
            if(data < mini){
                s.push(2*data - mini);
                mini = data;
            }
            else{
                s.push(data);
            }
        }
    }
    int pop(){
        if(s.empty()){
            return -1;
        }
        else{
            int curr = s.top();
            s.pop();
            if(curr > mini ){
                return curr;
            }
            else{
                int prevMin = mini;
                int val = 2*mini - curr;
                mini = val;
                return prevMin;
            }
        }
    }
    int top(){
        if(s.empty()){
            return -1;
        }
        else{
            int curr = s.top();
            if(curr < mini ){
                return mini;
            }
                return curr;
            
        }
    }
    bool isEmpty(){
        return s.empty();
    }
    int getMin(){
        if(s.empty()){
            return -1;
        }
        else
        return mini;
    }
};

int main(){
    specialStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << stack.getMin() << endl;
}