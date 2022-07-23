#include<iostream>
using namespace std;
// node creation
class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data" << value << endl;
    }
};
// insertion at head
void insertAtHead(Node *&head, int d)
{

    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

// printing
void print(Node *&head)
{

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// inserting at tail
void insertAtTail(Node *&tail, int d)
{
    // new node create
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next; // tail = temp;
}

// insertion at middle supposse you want to add 22 at third position
void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    // if the asked position is 1
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    // updating the tail
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }
    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}
Node*  KReverse(Node* head, int k){
    //base case
    if(head == NULL){
        return NULL;
    }

    //step1 reverse 1st k nodes
    Node* next = NULL;
    Node* curr = head;
    Node*  prev = NULL;
    int count = 0;
    while( curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next != NULL){
        head->next = KReverse(next, k);
    }
    return prev;
}

int main(){
    Node* head = new Node(10);
    insertAtHead(head,20);
    insertAtHead(head,25);
    insertAtHead(head,30);
    insertAtHead(head,35);
    insertAtHead(head,40);
    print(head);
    head = KReverse(head, 2);
    print(head);


}