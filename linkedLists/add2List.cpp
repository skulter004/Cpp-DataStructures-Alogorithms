#include<iostream>
using namespace std;
// resolve the error of output
.....
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
void insertAtTail( Node* &head,Node* &tail, int data){
    //empty list
    if(tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

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
    return curr;
}
// Node* addList(Node* head1, Node* head2){
//     int carry = 0 ;
//     Node* ansHead = NULL;
//     Node* ansTail = NULL;

//     while(head1 != NULL && head2 != NULL){
//         
//         int sum = carry + head1->data + head2->data;
//         int digit = sum % 10;
//         //creating node and inserting ans in the list
//         insertAtTail(ansHead,ansTail, digit);
//         cout << ansHead->data;
//         carry = sum / 10;
//         head1 = head1->next;
//         head2 = head2->next;
//     }

//     while(head1 != NULL){
//         int sum = carry + head1->data;
//         int digit = sum % 10;
//         insertAtTail(ansHead, ansTail, digit);
//         carry = sum / 10;
//         head1 = head1->next;
//     }
    
//     while(head2 != NULL){
//         int sum = carry + head2->data;
//         int digit = sum % 10;
//         insertAtTail(ansHead, ansTail,digit);
//         carry = sum /10;
//         head2 = head2->next;
//     }
//     while(carry != 0){
//         int sum = carry;
//         int digit = sum % 10;
//         insertAtTail(ansHead, ansTail, digit);
//         carry = sum / 10;
//     }

//     return ansHead;

// } 

Node* addList(Node* head1, Node* head2){
    int carry = 0 ;
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while(head1 != NULL || head2 != NULL || carry != 0){
        //generic code
        int val1 = 0;
        if(head1 != NULL)
        val1 = head1->data;

        int val2 = 0;
        if(head2 != NULL )
        val2 = head2->data;
        int sum = carry + head1->data + head2->data;
        int digit = sum % 10;

        //creating node and inserting ans in the list
        insertAtTail(ansHead,ansTail, digit);
        carry = sum / 10;

        if(head1 != NULL)
            head1 = head1->next;
        
        if(head2 != NULL){
            head2 = head2->next;
        }
        
    }
    
    return ansHead;

} 
Node* addTwoLists(Node* head1, Node* head2){
    // reversing both the list
    head1 = reverse(head1);
    head2 = reverse(head2);

    Node* ans = addList(head1, head2);
    return ans;
}



int main(){
    Node* head1 = new Node(2);
    Node* tail1 = head1;
    insertAtTail(head1, tail1, 3);
    insertAtTail(head1, tail1,4);

    Node* head2 = new Node(4);
    Node* tail2 = head2;
    insertAtTail(head2,tail2, 9);
    print(head1);
    head1 = addTwoLists(head1,head2);
    print(head1);
}