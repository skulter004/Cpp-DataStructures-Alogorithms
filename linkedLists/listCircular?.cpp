#include <iostream>
using namespace std;

// node creation
class Node
{
public:
    int data;
    Node *next;

    // cons
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    // dest
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free" << endl;
    }
};
void insertNode(Node *&tail, int element, int data)
{
    // empty list
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
        temp->next = temp;
    }
    // not empty
    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

// print
void print(Node *&tail)
{
    if (tail == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
}

bool isCircularList(Node* head){
    //empty list
    if(head == NULL){
        return true;
    }
    Node* temp = head->next;
    while( temp!= NULL && temp != head){
        temp = temp->next;
    }

    if(temp == head){
        return true;
    }
    return false;
}
int main()
{
    Node *tail = NULL;
    insertNode(tail, 5, 3);
    print(tail);
    cout << endl;
    insertNode(tail, 3, 4);
    print(tail);
    cout << endl;
    insertNode(tail, 4, 5);
    print(tail);
    cout << endl;
    insertNode(tail, 4, 4);
    print(tail);
    cout << endl;
    if(isCircularList(tail)){
        cout << "circular in nature " << endl;
    }
    else{
        cout << "not circular " << endl;
    }
}