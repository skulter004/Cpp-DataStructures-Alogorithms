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

//one approach is that ke inorder of a BST is always in a sorted order for we can use it for  validation
//second approach is  that ke we can check that the values on the left of the tree should be less that \
the current value  and on the right side it should be greater than the current value 
bool isBST(Node* root, int min, int max){
    //base
    if(root == NULL){
        return true;
    }
    if(root->data >= min && root->data <= max){
        bool left = isBST(root->left, min, max);
        bool right = isBST(root->right, root->data, max);
        return (left && right);
    }
    else{
        return false;
    }
}

int main(){ 
    Node* root = NULL;
    cout <<"Enter data to create BST" << endl;
    takeInput(root);
    if(isBST(root, INT_MIN, INT_MAX))
        cout << "is a valid BSt" << endl;

    else 
        cout << "is not a valid BST" << endl;
}