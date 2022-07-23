#include<iostream>
using namespace std;

class twoStack{
    //properties
    public:
    int *arr;
    int top1;
    int top2;
    int size;
    //behaviour
    twoStack(int size){
        this -> size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }
    //funtions
    void push1(int element){
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = element;
        }
        else{
            cout << "Stack1 overflow " << endl;
        }
    }
    void push2(int element){
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = element;
        }
        else{
            cout << "Stack2 overflow " << endl;
        }
    }

    void pop1(){
        if(top1 >= 0){
            top1--;
        }
        else{
            cout << " Stack1 underflow " << endl;
        }
    }
    void pop2(){
        if(top2 < size){
            top1++;
        }
        else{
            cout << " Stack2 underflow " << endl;
        }
    }

    int peek1(){
        if(top1 >= 0){
            return arr[top1];
        }
        else{
            cout << "stack1 is empty " << endl;
            return -1;
        }
    }
    int peek2(){
        if(top2 < size){
            return arr[top2];
        }
        else{
            cout << "stack 2 is empty " << endl; 
            return -1;
        }
    }
};

int main(){
    twoStack st(6);
    cout << st.peek1() << endl;
    st.push1(6);
    st.push1(5);
    st.push1(4);
    st.push2(1);
    st.push2(2);
    st.push2(3);

    cout << st.peek1() << endl;

}
