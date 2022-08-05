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

Node* LCAinBST(Node* root, Node* p, Node* q){
    if(root == NULL){
        return NULL;
    }
    if(root->data < p->data && root->data < q->data){
        return LCAinBST(root->right, p, q);
    }
    if(root->data > p->data && root->data > q->data){
        return LCAinBST(root->left, p, q);
    }
    return root;
}

Node* functionCall(Node* root, int key1, int key2){

    Node* temp1 = root;
    Node* temp2 = root;
    while(temp1->data != key1){
        if(temp1->data > key1)  temp1 = temp1->left;

        else temp1 = temp1->right;
    }
    while(temp2->data != key2){
        if(temp2->data > key2)  temp2 = temp2->left;

        else temp2 = temp2->right;
    }
    return LCAinBST(root, temp1, temp2);
}

int main(){ 
    Node* root = NULL;
    cout <<"Enter data to create BST" << endl;
    takeInput(root);
    int k1, k2; cout << "enter the two keey nodes for which you want to search LCA " << endl;
    cin >> k1 >> k2;
    cout << "The LCA is " << functionCall(root, k1, k2 )->data << endl;
}