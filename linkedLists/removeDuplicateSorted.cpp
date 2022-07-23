#include<iostream>
using namespace std;
//complete the code it have some errors

//node creation
class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //destructor 
    ~Node(){
        int value = this->data;
        //memory free
        if(this->next != NULL){
            delete next;
            this-> next = NULL;
        }
        cout << "memory is free for node with data" << value <<endl;
    }
    
};
//insertion at head
void insertAtHead(Node* &head , int d){

    //new node create
    Node* temp = new Node(d);
    temp-> next = head;
    head = temp;
}

//printing 
void print(Node* &head){

    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp->next;
    }
    cout << endl;
}
//inserting at tail
void insertAtTail(Node* &tail,int d){
    //new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail->next;//tail = temp;
}

//insertion at middle supposse you want to add 22 at third position
void insertAtPosition(Node* &head, Node* &tail, int position, int data){
    //if the asked position is 1
    if(position == 1){
        insertAtHead(head,data);
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
        insertAtTail(tail , data);
        return;
    }
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

.......
//remove duplicates
Node* removeDuplicates(Node* head){
    if(head == NULL){
        return NULL;
    }

    //non empty list
    Node* curr = head;

    while(curr->next != NULL && curr != NULL){

        if( curr -> data == curr -> next -> data ){
            Node* next_next = curr->next->next;
            delete curr->next;
            curr->next = next_next;
        }
        else{
            curr = curr->next;
        }
    }

    return head;
}

int main(){
    Node* head= new Node(10);
    insertAtHead(head, 8);
    insertAtHead(head, 8);
    insertAtHead(head, 5);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    print(head);
    head = removeDuplicates(head);
    cout << head->next->next->data << endl;

    print(head);
}