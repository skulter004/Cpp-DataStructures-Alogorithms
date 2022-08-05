#include<iostream>
using namespace std;

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

//deletion by position
void deletePosition(Node* &head, Node* &tail, int position){
    //deleting fisrt node
    if(position == 1){
        Node* temp = head;
        head = head->next;
        //free memory of 1st node;
        temp->next = NULL;
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
        //handling the tail
        if(curr->next == NULL){
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

//deletion by data incomplete
void deleteData(Node* &head, Node* &tail, int data){
    Node* temp = head;
    //deleting head node
    if(head->data == data){
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* prev = head;
        Node* curr = head;

    while(prev->next != NULL){

        if(curr->data == data){
            prev->next = curr->next;
            return;
        }
            prev = curr;
            curr = curr->next;
            
        }
        //handling the tail
        if(prev->next == NULL && prev->data == data){
            tail = prev;
        }
        
        
    }
    }
    

int main(){

    //creat a node
    Node* node1 = new Node(10);
    //cout << node1->next << endl;
    //cout << node1->data << endl;

    //head pointed to node
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtTail(tail , 12);
    print(head);

    insertAtTail(tail,15);
    print(head);

    insertAtTail(tail,16);
    print(head);
    
    insertAtPosition(head, tail,5,22);
    print(head);

    cout <<"head " << head->data << endl;
    cout <<"tail " << tail->data << endl;

    deletePosition(head, tail, 5);
    print(head);
    cout <<"head " << head->data << endl;
    cout <<"tail " << tail->data << endl;

    cout << "delete by data called" << endl;
    deleteData(head,tail,16);
    print(head);
    cout <<"head " << head->data << endl;
    cout <<"tail " << tail->data << endl;

}