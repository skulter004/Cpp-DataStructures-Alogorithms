#include<bits/stdc++.h>
using namespace std;

class Queue{
    int *arr;
    int size;
    int front = 0;
    int rear = 0;

    public:
    Queue(int size){
        this->size = size;
        arr = new int[size];
    }
    void enQueue(int data){
        if(rear == size){
            cout << "Queue is full" << endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }
    int deQueue(){
        if(front == rear){
            return -1;
        }
        else{
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
            return  ans;
        }
    }

    int Front(){
       if(front == rear){
            return -1;
        }
        else{
            return arr[front];
        } 
    }

    bool isEmpty(){
        if(front == rear){
            return true;
        }
        else
        return false;
    }

};

int main(){
    Queue q(5);
    q.enQueue(5);
    q.enQueue(6);
    q.enQueue(7);
    cout << q.Front() << endl;
    q.deQueue();
    q.deQueue();
    q.deQueue();
    if(q.isEmpty())
        cout << "queue is empty " << endl;
    else
        cout << "queue is not empty " << endl;
}