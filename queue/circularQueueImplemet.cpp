#include<bits/stdc++.h>
using namespace std;

class circularQueue{
    int *arr;
    int size;
    int front = -1;
    int rear = -1;

    public:
    circularQueue(int size){
        this->size = size;
        arr = new int[size];
    }
    void enQueue(int data){
        if(front == 0 && rear == size-1 || rear == front-1){
            cout << "Queue is full" << endl;
        }
        else if(front == -1){
            front = rear = 0;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = data;
    }
    int deQueue(){
        if(front == -1){
            cout << "queue is empty cannot delete " << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;

        if(front == rear){
            front = rear = -1;
        }
        else if(front == size-1){
            front = 0;
        }
        else{
            front++;
        }
        return ans;
    }

    int Front(){
       if(front == -1){
            return -1;
        }
        else{
            return arr[front];
        } 
    }

    bool isEmpty(){
        if(front == -1){
            return true;
        }
        else
        return false;
    }

};

int main(){
    circularQueue q(5);
    cout << q.Front() << endl;
    q.enQueue(3);
    q.enQueue(3);
    q.enQueue(3);
    q.enQueue(3);
    q.enQueue(3);
    q.deQueue();
    q.enQueue(3);
    cout << q.isEmpty() << endl;

}