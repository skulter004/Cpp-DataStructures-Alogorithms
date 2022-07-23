#include<iostream>
#include<map>
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

//detectin cycle/loop
bool detectLoop(Node* head){
    if(head == NULL){
        return false;
    }
    map<Node*,bool> visited;

    Node* temp = head;

    while(temp != NULL){

        //cycle present
        if(visited[temp] == true){
            cout << "present on element " << temp->data << endl;
            return 1;            
        }
        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

//floyed cycle detection algo
Node* floyd(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && slow != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }

        slow = slow->next;

        if(slow == fast){
            cout << "cycle present at " << slow->data << endl;
            return slow;
        }
    }

    return NULL;
}

//get starting node of intersection
Node* getStart(Node* head){
    if(head == NULL){
        return NULL;
    }
    
    Node* intersection = floyd(head);
    Node* slow = head;

    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

//remove loop
void removeLoop(Node* head){
    if(head == NULL){
        return;
    }

    Node* start = getStart(head);
    Node* temp = start;

    while(temp->next != start){
        temp = temp->next;
    }

    temp->next = NULL;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    insertAtPosition(head, tail, 4, 22);
    print(head);

    //cycling loop in list
    tail->next = head->next;

    if(floyd(head))
    cout << "lsit contains a cycle " << endl;
    else
    cout << "list does not have a cycle " << endl;
    Node* loop = getStart(head) ;
    cout << "starting at " << loop->data<< endl;
    removeLoop(head);
    print(head);
    
    //rechecking if the loop is removed or not
    if(floyd(head))
    cout << "lsit contains a cycle " << endl;
    else
    cout << "list does not have a cycle " << endl;

    return 0;
}