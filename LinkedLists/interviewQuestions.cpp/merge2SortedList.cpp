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


Node* solve(Node* head1, Node* head2){
    //if only 1 element in 1st list
    if(head1->next == NULL){
        head1->next = head2;
        return head1;
    }

    Node* curr1 = head1;
    Node* next1 = head1->next;
    Node* curr2 = head2;
    Node* next2 = curr2->next;

    while(next1 != NULL && curr2 != NULL){
        if(curr1->data <= curr2->data && curr2->data <= next1->data){
            //inserting the new node
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        }
        else{
            //moving to next nodes
            curr1 = next1;
            next1 = next1->next;

            //if the first list is ended
            if(next1 == NULL){
                curr1->next = curr2;
            }
        }

    }
    return head1;
}
Node* merge2Sorted(Node* head1, Node* head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    
    if(head1->data <= head2->data){
        return solve(head1, head2);
    }
    else{
        return solve(head2, head1);
    }

}
int main(){
    Node* head1 = new Node(2);
    Node* tail1 = head1;
    insertAtTail(tail1, 3);
    insertAtTail(tail1, 7);
    insertAtTail(tail1, 9);
    insertAtTail(tail1, 13);
    insertAtTail(tail1, 14);
    insertAtTail(tail1, 18);

    Node* head2 = new Node(4);
    Node* tail2 = head2;
    insertAtTail(tail2, 9);
    insertAtTail(tail2, 15);
    insertAtTail(tail2, 16);
    insertAtTail(tail2, 18);
    insertAtTail(tail2, 19);

    head1 = merge2Sorted(head1, head2);

    print(head1);
}