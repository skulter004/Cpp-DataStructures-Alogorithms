#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data" << endl;
    }
};
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void  getLength(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    cout << "length is " << len << endl;
}

void insertAtHead(Node* &head, Node* &tail , int data){
    //empty list
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
    Node* temp =  new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
    }

}

void insertAtTail( Node* & head,Node* & tail, int data){
    //empty list
    if(tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }
    Node* temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data){
    if(position == 1){
        insertAtHead(head,tail, data);
        return;
    }
    Node* temp = head;
    int count = 1;
    while(count < position-1){
        temp = temp->next;
        count++;
    }
    //updating the tail
    if(temp-> next == NULL){
        insertAtTail(head,tail , data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;

}
//deletion by position
void deletePosition(Node* &head, Node* &tail, int position){
    //deleting fisrt node
    if(position == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        //free memory of 1st node;
        delete temp;
    }
    else{
        //deleting a middle or last node
        Node* curr = head;
        Node* prev = NULL;
        
        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr->next;
            count++;
          
        }
        //handling tail
        if(curr->next == NULL){
            tail = curr->prev;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;

        //free mem
        delete curr;
    }
}
int main(){
    Node* node1 = new Node(10);
    Node* head =  node1;
    Node* tail = node1;
    print(head);
    getLength(head);
    insertAtHead(head, tail, 11);
    print(head);
    getLength(head);
    insertAtTail(head,tail, 25);
    print(head);
    insertAtPosition(head, tail, 2, 100);
    print(head);
    insertAtPosition(head, tail, 1, 101);
    print(head);
    insertAtPosition(head, tail, 5, 105);
    print(head);
    deletePosition(head, tail, 2);
    print(head);deletePosition(head, tail, 5);
    print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;
    return 0;
}