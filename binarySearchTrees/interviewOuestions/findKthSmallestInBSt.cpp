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

//inorder traversal is sorted to we can use the approach
int kSmallest(Node* root,int k, int &count){
    if(root == NULL){
        return -1 ;
    }
    kSmallest(root -> left, k, count);
    int ans =  root -> data;
    count++;
    if(count == k) return ans;
    kSmallest(root -> right, k, count);
}
// same approach for the k largest value

int main(){ 
    Node* root = NULL;
    cout <<"Enter data to create BST" << endl;
    takeInput(root);
    int k; cout << "enter the value of k " << endl;
    cin >> k; int count = 0 ;
    cout << k <<" smallest element is "<< kSmallest(root, k, count ) << endl;
}