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
//1st method create array copy the elements of \
list and apply the logic of array of palindromes sp com = O[n] t com = O[n]
//2nd method divide list in 2 parts and compare the 2nd part after reversing

Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
bool palindromeList(Node* head){
    
    if(head == NULL){
        return true;
    }
    
    Node* mid = getMid(head);

    //reverse list after mid

    Node* temp = mid->next;
    mid-> next = reverse(temp);

    //compare both halfs
    Node* head1 = head;
    Node* head2 = mid->next;

    while(head2 != NULL){
        if(head1->data != head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    //again reverse the list after mid so the list will remain as it was
    temp = mid->next;
    mid-> next = reverse(temp);

    return true;
}
int main(){
    Node* head1 = new Node(2);
    Node* tail1 = head1;
    insertAtTail(tail1, 1);
    insertAtTail(tail1, 2);

    cout << palindromeList(head1) << endl;
}