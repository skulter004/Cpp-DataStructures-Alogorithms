#include<iostream>
using namespace std;

class dQueue{
    int *arr;
    int front;
    int rear;
    int size;
public:
    dQueue(int n){
        this->size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool pushFront(int data){
        if(isFull()){
            cout << "queue is already full cannot insert " << endl;
            return false;
        }
        else if(isEmpty()){
            front = rear = 0;
        }
        else if(front == 0 && rear != size-1){
            front = size-1;
        }
        else{
            front--;
        }
        arr[front] = data;
        return true;
    }

    bool pushRear(int data){
        if(isFull()){
            return false;
        }
        else if(isEmpty()){
            front = rear = 0;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = data;
        return true;
    }

    int popFront(){
        if(isEmpty()){
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

    int popRear(){
        if(isEmpty()){
            cout << "queue is empty cannot delete " << endl;
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        if(front == rear){
            front = rear = -1;
        }
        else if(rear == 0){
            rear = size-1;
        }
        else{
            rear--;
        }
        return ans;
    }

    int getFront(){
        if(front == -1){
            return -1;
        }
        return arr[front];
    }

    int getRear(){
        if(front == -1){
            return -1;
        }
        return arr[rear];
    }
    
    bool isEmpty(){
        if(front == -1){
            return true;
        }
        return false;
    }

    bool isFull(){
        if(front == 0 && rear == size-1 || front != 0 && rear == front -1){
            return true;
        }
        return false;
    }

};

int main(){
    dQueue q(2);
    q.pushFront(1);
    q.pushRear(2);
    cout << q.isEmpty() << endl;
    cout << q.isFull() << endl;
    q.popFront();
    cout << q.isFull() << endl;
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
}