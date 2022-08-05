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

//for every node the diffrence of height of left and right \
subtree should be no more than 1 
//wwe can use inordder approach again as its sorted

void inorder(Node* root, vector<int> &in){
    if(root == NULL){
        return ;
    }
    inorder(root -> left, in);
    in.push_back(root->data);
    inorder(root -> right, in);
}

Node* inOrderToBST(int s, int e, vector<int> &inOrderVal){
    //base
    if(s > e) return NULL;

    int mid = (s+e)/2;
    Node* root = new Node(inOrderVal[mid]);
    root->left = inOrderToBST(s, mid-1, inOrderVal);
    root->right = inOrderToBST(mid+1, e, inOrderVal);
    return root;

}

Node* balancedBST(Node* root){
    vector<int> inOrderVal;
    inorder(root, inOrderVal);

    return inOrderToBST(0, inOrderVal.size()-1, inOrderVal);


}

//driver code just to check that the inroder of the balanced tree is correct
void inorderPrint(Node* root){
    if(root == NULL){
        return ;
    }
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main(){
    Node* root = NULL;
    cout <<"Enter the data to create BST" << endl;
    takeInput(root);
    inorderPrint(root);
    cout << endl;
    Node* newRoot = balancedBST(root);
    inorderPrint(newRoot);
}