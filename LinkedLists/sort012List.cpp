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

//data replace ment approach
Node* sortList(Node* head){
    int count_0 = 0;
    int count_1 = 0;
    int count_2 = 0;

    Node* temp = head;

    while(temp != NULL){
        if(temp->data == 0)
            count_0++;
        else if(temp->data == 1)
            count_1++;
        else if(temp->data == 2)
            count_2++;
        
        temp = temp->next;
    }    

    temp = head;
    while(temp != NULL){
        if(count_0 != 0){
        temp->data = 0;
        count_0--;
        }
        else if(count_1 != 0){
        temp->data = 1;
        count_1--;
        }
        else if(count_2 != 0){
        temp->data = 2;
        count_2--;
        }
        temp = temp->next;
    }

    return head;
}

void insertAtTailnew(Node* &tail, Node* curr){
    tail->next = curr;
    tail = curr;
}

....
//2nd approach
Node* sortList2(Node* head){
    //dumy nodes
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twohead = new Node(-1);
    Node* twoTail = twohead;

    Node* curr = head;

// created sepreate lists
    while(curr != NULL){

        int value = curr->data;

        if(value == 0)
        insertAtTailnew(zeroTail, curr);
        
        else if(value == 1)
        insertAtTailnew(oneTail, curr);

        else if(value == 2)
        insertAtTailnew(twoTail, curr);

        curr = curr->next;
    }

    // w'll merge the three lists
    
    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    }
    else{
        zeroTail->next = twohead->next;
    }

    oneTail->next = twohead->next;
    twoTail->next = NULL;
    
    //setup head
    head = zeroHead->next;

    //deleting dumy nodes
    delete zeroHead;
    delete oneHead;
    delete twohead;

    return head;
}

int main(){
    Node* head= new Node(0);
    insertAtHead(head, 0);
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 0);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    print(head);
    head  = sortList2(head);
    print(head);
}