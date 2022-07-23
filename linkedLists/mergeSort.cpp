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
void insertAtTail(Node* &head, Node* &tail,int d){
    //new node create
    Node* temp = new Node(d);

    if(head == NULL){
        head = temp;
        tail = temp;
    }
    else{
    tail -> next = temp;
    tail = tail->next;//tail = temp;
    }
}
//get mid point
Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head->next ;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* merge(Node* left, Node* right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }

    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left != NULL && right != NULL){
        if(left->data < right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left != NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while(right != NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;

    return ans;
}
Node* mergeSort(Node* head){
    //base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* mid = getMid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    //recursive calls
    left = mergeSort(left);
    right = mergeSort(right);

    //merge both left and right halfs

    Node* result = merge(left, right);
    
    return result;
}

int main(){

    Node* head2 = new Node(19);
    Node* tail2 = head2;
    insertAtTail(head2, tail2, 4);
    insertAtTail(head2, tail2, 45);
    insertAtTail(head2, tail2, 6);
    insertAtTail(head2, tail2, 32);
    insertAtTail(head2, tail2, 9);
    head2 = mergeSort(head2);
    print(head2);
}