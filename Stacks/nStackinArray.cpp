#include<bits/stdc++.h>
using namespace std;

class nStack{
    int *arr;
    int *top;
    int *next;
    int n, s;
    int freeSpot;

    public: 

    nStack(int N, int S){
        n = N;
        s = S;
        arr = new int[S];
        top = new int[n];
        next = new int[s];

        //top innitialize
        for(int i = 0; i < n; i++){
            top[i] = -1;
        }

        //next initilize
        for(int i = 0; i < s; i++){
            next[i] = i+1;
        }

        next[s-1] = -1;

        freeSpot = 0;
    }
    bool push(int x, int m){
        if(freeSpot == -1)
        return false;
        else{
            //find index
            int index = freeSpot;
            //update free spot
            freeSpot = next[index];
            //insert element
            arr[index] = x;
            //update next index
            next[index] = top[m-1];
            //update top
            top[m-1] = index;

            return true;
        }
    }
    int pop(int m){
        if(top[m-1] == -1){
            return -1;
        }
        //coming backwords whar we have done in push function
        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};

int main(){ 
    int N = 3;
    int S = 6;
    nStack stack(S, N);
    stack.push(1,1);
    stack.push(2,2);
    stack.push(3,3);
    cout << stack.pop(1) << endl;
    cout << stack.pop(2) << endl;
    cout << stack.pop(3) << endl;
    cout << stack.pop(1) << endl;
}