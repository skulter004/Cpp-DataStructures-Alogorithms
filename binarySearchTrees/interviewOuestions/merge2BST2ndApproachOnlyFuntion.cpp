#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    // seperator
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // previos level traversed
            cout << endl;
            // still elements in the tree
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

Node *insertIntoBST(Node* root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeInput(Node* &root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}



//segmentation

void convertIntoSortedLL(Node* root, Node* &head){
    if(root == NULL) return ;

    convertIntoSortedLL(root->right,head);
    root->right = head;
    if(head == NULL)
        head->left = root;
    
    head = root;
    convertIntoSortedLL(root->left, head);
}

Node* merge2SoretedLL(Node* head1, Node* head2){
    Node* head = NULL;
    Node* tail = NULL;
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{
            if(head == NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while(head1 != NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while(head2 != NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

int countNodes(Node* head){
    int cnt = 0;
    while(head->right != NULL){
        cnt++;
        head = head->right;
    }
    return cnt;
}

Node* sortedLLtoBST(Node* &head, int n){
    if(n <= 0 || head == NULL) return NULL;

    Node* left = sortedLLtoBST(head, n/2);
    Node* root = head;
    root->left = left;

    head = head->right;
    root->right = sortedLLtoBST(head, n - n/2-1);
    return root;
}

Node* merge2BST(Node* root1, Node* root2){
    //step1 convert BST to LL
    Node* head1 = NULL;
    convertIntoSortedLL(root1, head1);
    head1->left = NULL;

    Node* head2 = NULL;
    convertIntoSortedLL(root2, head2);
    head2->left = NULL;

    //step 2 merge sorted ll
    Node* head =  merge2SoretedLL(head1, head2);
    //convert sorted LL to BST
    return sortedLLtoBST(head, countNodes(head));
}

int main(){
    Node* root1 = NULL;
    cout <<"Enter the data to create 1st BST" << endl;
    takeInput(root1);
    
    Node* root2 = NULL;
    cout <<"Enter the data to create 2nd BST" << endl;
    takeInput(root2);
    Node* newTree = merge2BST(root1, root2);
    levelOrderTraversal(newTree);
}