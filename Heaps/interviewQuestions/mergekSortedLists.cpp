#include<iostream>
#include<queue>
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
void insertAtHead(Node* &head , int data){
    //empty list
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
    }
    else{
    Node* temp =  new Node(data);
    temp->next = head;
    head = temp;
    }

}
void print(Node* &head){

    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp->next;
    }
    cout << endl;
}
//1st put all element of list into vector then join all lists\
then replace the data of the lists;
//complexity of sorting nlogn

class compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};


Node* mergeKLists(vector<Node*> Lists){
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    int k = Lists.size();

    if(k == 0) return NULL;
    //1st step
    for(int i = 0; i < k; i++){
        if(Lists[i] != NULL){
            minHeap.push(Lists[i]);
        }
    }

    Node* head = NULL;
    Node* tail = NULL;

    while(minHeap.size() > 0){
        Node* top = minHeap.top();
        minHeap.pop();

        if(top->next != NULL){
            minHeap.push(top->next);
        }

        if(head == NULL){//list empty
            head = top;
            tail = top;
        }
        else{//insert at end
            tail->next = top;
            tail = top ;
        }
    }
    return head;
}

   

int main(){
    vector<Node*> lists;
    int k; cout << "enter the number of lists" << endl;
    cin >> k;
    int n = 5;
    for(int j = 1; j <= k; j++){
        Node* head = NULL ;
        for(int  i = 0; i < n; i++){
            int data; 
            cout << "enter " << j << " list data" << endl;
            cin >> data;
            insertAtHead(head,data );
        }
        lists[j] = head;
    }
    Node* head = mergeKLists(lists);
    print(head);
}