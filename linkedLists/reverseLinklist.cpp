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

// Node* reverseList(Node* head){
//     //iterative
//     if(head == NULL || head->next == NULL){
//         return head;
//     }
//     Node* prev = NULL;
//     Node* curr = head;
//     Node* forward = NULL;
//     while(curr != NULL){
//         forward = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = forward;
//     }
//     return prev;
// }

//recurrsivemethod
void reverseList(Node* &head , Node* curr, Node* prev){
    //base case
    if(curr == NULL){
        head = prev;
        return;
    }
    Node* forwrd = curr->next;
    reverseList(head, forwrd, curr);
    curr->next = prev;
}

Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    reverseList(head, curr, prev);
    return head;

}

int main(){
    Node* head = new Node(10);
    insertAtHead(head,20);
    insertAtHead(head,25);
    insertAtHead(head,30);
    print(head);
    cout << head->data << endl;
    head = reverse(head);
    print(head);

    
    
}